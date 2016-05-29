#include <bits/stdc++.h>
#include <zmqpp/zmqpp.hpp>

using namespace std;
using namespace zmqpp;

unordered_map<string, int> peer_id;
unordered_map<int, message> buffer;
const int MNODES = 20;

void dispatch_peer(socket &peers, message &req) {
  string id, text;
  req >> id >> text;
  cout << "Received " << text << endl;
  if (text == "start") {
    if (!peer_id.count(id))
      peer_id[id] = peer_id.size();
    message res;
    res << id << "id" << MNODES << peer_id[id];
    peers.send(res);
  }
  if (text == "receive") {
    int source;
    req >> source;
    message res;
    res.copy(buffer[source]);
    res.push_front("receive");
    res.push_front(id);
    peers.send(res);
  }

  if (text == "send") {
    int source;
    req >> source;
    buffer[source].copy(req);
  }

  if (text == "end") {
    peer_id.erase(id);
  }
}

int main(int argc, char **argv) {
  context ctx;
  socket peers(ctx, socket_type::router);
  peers.bind(argv[1]);
  poller pol;
  pol.add(peers);

  message request;
  while (true) {
    if (pol.poll()) {
      if (pol.has_input(peers)) {
        peers.receive(request);
        dispatch_peer(peers, request);
      }
    }
  }

  return 0;
}
