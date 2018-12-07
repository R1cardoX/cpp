#if 0
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define Square(a) (Pow(a,2))
#define Cube(a) (Pow(a,3))
#define Abs(a) ((a)>(0)?(a):(-(a)))
#define all(x) (x).begin(),(x).end()
#define showVec(x) do{cerr<<"vector:"<<(#x)<<endl;for(auto var:x) cerr<<var<<" ";cerr<<endl;}while(0)
#define showList(x) do{cerr<<"list:"<<(#x)<<endl;for(auto var:x) cerr<<var<<" ";cerr<<endl;}while(0)
#define showSet(x) do{cerr<<"set:"<<(#x)<<endl;for(auto var:x) cerr<<var<<" ";cerr<<endl;}while(0)
#define showMap(x) do{cerr<<"map:"<<(#x)<<endl;for(auto var:x) cerr<<(var).first<<","<<(var).second<<endl;}while(0)
#define showVeec(x) do{cerr<<"vector:"<<(#x)<<endl;for(auto b:x){for(auto a:b)cerr<<a<<" ";cerr<<endl;}}while(0)
#define debug(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cerr<<str<<" = "<<t<<endl;}
template <class T, class... S> void dbs(string str,T t,S... s) {int idx = str.find(','); cerr<<str.substr(0, idx)<<" = "<<t<<" , ";dbs(str.substr(idx + 1), s...);}
typedef long long ll;
inline int Pow(int a,int b) {int ans=1,base=a; while(b!=0) {if((b&1)!=0) ans*=base; base*=base; b>>=1;} return ans;}
#endif
