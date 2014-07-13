using namespace std;
#include<bits/stdc++.h>

int main() {

  ios_base::sync_with_stdio(false);cin.tie(NULL);
  map<int, int> mio;  mio[0] = 0;mio[1] = 1;mio[2] = 4;mio[3] = 12;mio[4] = 24;mio[5] = 36;mio[6] = 60;mio[7] = 192;mio[8] = 120;mio[9] = 180;mio[10] = 240;mio[11] = 576;mio[12] = 360;mio[13] = 1296;mio[14] = 900;mio[15] = 720;mio[16] = 840;mio[17] = 9216;mio[18] = 1260;mio[19] = 786432;mio[20] = 1680;mio[21] = 2880;mio[22] = 15360;mio[23] = 3600;mio[24] = 2520;mio[25] = 6480;mio[26] = 61440;mio[27] = 6300;mio[28] = 6720;mio[30] = 5040;mio[32] = 7560;mio[33] = 46080;mio[34] = 983040;mio[35] = 25920;mio[36] = 10080;mio[38] = 32400;mio[39] = 184320;mio[40] = 15120;mio[41] = 44100;mio[42] = 20160;mio[44] = 107520;mio[45] = 25200;mio[48] = 27720;mio[49] = 233280;mio[50] = 45360;mio[52] = 430080;mio[53] = 129600;mio[54] = 50400;mio[55] = 414720;mio[56] = 60480;mio[59] = 921600;mio[60] = 55440;mio[63] = 100800;mio[64] = 83160;mio[66] = 322560;mio[68] = 176400;mio[70] = 181440;mio[72] = 110880;mio[75] = 226800;mio[80] = 166320;mio[81] = 352800;mio[84] = 221760;mio[88] = 967680;mio[90] = 277200;mio[95] = 705600;mio[96] = 332640;mio[100] = 498960;mio[105] = 907200;mio[108] = 554400;mio[112] = 665280;mio[120] = 720720;
  int a; cin>>a;
  for (int i = 0; i < a; ++i) {
    int b; cin>>b;
    if (mio.count(b))
      cout<<mio[b]<<'\n';
    else
      cout<<"Too big"<<'\n';
  }
  return 0;

}
