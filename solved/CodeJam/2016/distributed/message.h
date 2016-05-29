#include <zmqpp/zmqpp.hpp>
#include <bits/stdc++.h>
#include <thread>

using namespace zmqpp;
using namespace std;

// maximum number of nodes
int MNODES;
int myId;

context ctx;
socket router(ctx, socket_type::dealer);
vector<message> buffer_out, buffer_in;

// Register in the local environment
void mp_register(char *endpoint) {
  router.connect(endpoint);
  message m;
  m << "start";
  router.send(m);

  poller pol;
  pol.add(router);

  message request;
  router.receive(request);
  string text;
  request >> text;
  assert(text == "id");
  request >> MNODES >> myId;
  buffer_out.resize(MNODES);
  buffer_in.resize(MNODES);
}

void mp_end() {
  message m;
  m << "end";
  router.send(m);
}

// Start Google API.

// The number of nodes on which the solution is running.
int NumberOfNodes() {
  return MNODES;
}

// The index (in the range [0 .. NumberOfNodes()-1]) of the node on which this
// process is running.
int MyNodeId() {
  return myId;
}

// In all the functions below, if "target" or "source" is not in the valid
// range, the behaviour is undefined.

// The library internally has a message buffer for each of the nodes in
// [0 .. NumberOfNodes()-1]. It accumulates the message in such a buffer through
// the "Put" methods.

// Append "value" to the message that is being prepared for the node with id
// "target". The "Int" in PutInt is interpreted as 32 bits, regardless of
// whether the actual int type will be 32 or 64 bits.
void PutChar(int target, char value) {
  string tmp;
  tmp.push_back(value);
  buffer_out[target] << tmp;
}

void PutInt(int target, int value) {
  buffer_out[target] << value;
}

void PutLL(int target, long long value) {
  buffer_out[target] << (int64_t)value;
}

// Send the message that was accumulated in the appropriate buffer to the
// "target" instance, and clear the buffer for this instance.
//
// This method is non-blocking - that is, it does not wait for the receiver to
// call "Receive", it returns immediately after sending the message.
void Send(int target) {
  message m;
  m.copy(buffer_out[target]);
  m.push_front(target);
  m.push_front("send");
  router.send(m);
}

// The library also has a receiving buffer for each instance. When you call
// "Receive" and retrieve a message from an instance, the buffer tied to this
// instance is overwritten. You can then retrieve individual parts of the
// message through the Get* methods. You must retrieve the contents of the
// message in the order in which they were appended.
//
// This method is blocking - if there is no message to receive, it will wait for
// the message to arrive.
//
// You can call Receive(-1) to retrieve a message from any source, or with
// source in [0 .. NumberOfNodes()-1] to retrieve a message from a particular
// source.
//
// It returns the number of the instance which sent the message (which is equal
// to source, unless source is -1).
int Receive(int source) {
  if (source < 0) {
    cout << "NOT IMPLEMENTED YET"  << endl;
    assert(false);
  }
  message m;
  m << "receive" << source;
  router.send(m);
  router.receive(m);
  string text;
  int id_source;
  m >> text >> id_source;
  assert(text == "receive");
  buffer_in[source].copy(m);
  return id_source;
}

// Each of these methods returns and consumes one item from the buffer of the
// appropriate instance. You must call these methods in the order in which the
// elements were appended to the message (so, for instance, if the message was
// created with PutChar, PutChar, PutLL, you must call GetChar, GetChar, GetLL
// in this order).
// If you call them in different order, or you call a Get* method after
// consuming all the contents of the buffer, behaviour is undefined.
// The "Int" in GetInt is interpreted as 32 bits, regardless of whether the
// actual int type will be 32 or 64 bits.
char GetChar(int source) {
  string ans;
  buffer_in[source] >> ans;
  return ans[0];
}

int GetInt(int source) {
  int ans;
  buffer_in[source] >> ans;
  return ans;
}

long long GetLL(int source) {
  int64_t ans;
  buffer_in[source] >> ans;
  return ans;
}
