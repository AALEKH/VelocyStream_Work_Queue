#include <velocypack/vpack.h>
#include <iostream>
#include <typeinfo>

using namespace arangodb::velocypack;
using namespace std;

struct vparser{
  int a;
  string c;
};

struct velocystream{
  uint32_t length;
  uint32_t chunkx; // chunkx = chunk + isFirstChunk
  uint64_t messageId;
  uint64_t messageLength;
  arangodb::velocypack::Builder vpacks; // Collection of all Velocypacks
};

int main () {
  // create an object with attributes "b", "a", "l" and "name"
  // note that the attribute names will be sorted in the target VPack object!
  Builder bhj;
  bhj.add(Value("aaa"));
  ValueLength len;
  Builder bui;
  vparser st, st_t;
  velocystream velocy_one, velocy_two; //srt_l
  velocy_one.length = 100;
  velocy_one.chunkx = 12334;
  velocy_one.messageId = 12345;
  velocy_one.messageLength = 1;
  velocy_one.vpacks = bhj;
  velocy_two.length = 100;
  velocy_two.chunkx = 12335;
  velocy_two.messageId = 12346;
  velocy_two.length = 1;
  velocy_two.vpacks = bhj;
  cout << "Velocy One: "<< sizeof(velocy_one) << endl;
  st.a = 12;
  st.c = "string hello";
  const char *b;

  const char *c;

  const char *d;

  const char *elf;

  velocystream *srt_l = (velocystream *)malloc(1000);
  
  char ex[sizeof(velocy_one)];
  b = static_cast<char*>(static_cast<void*>(&st));
  c = static_cast<char*>(static_cast<void*>(&velocy_one));
  d = static_cast<char*>(static_cast<void*>(&velocy_two));
  
  bhj.add(Value(c));
  Slice s(bhj.start());
  elf = s.getString(len);

  memcpy(srt_l, c, 1000);
  cout << " Type: "<< typeid(c).name() << endl;

  Slice sl(srt_l->vpacks.start());
  string hell = sl.copyString();
  cout << "Hell: " << hell << endl;
  cout << "Length: "<< srt_l->length << " Chunkx: "<< srt_l->chunkx << " messageId: " << srt_l->messageId << " Message Length: "<< srt_l->messageLength << endl;
  std::cout << "Resulting VPack:" << std::endl;

}