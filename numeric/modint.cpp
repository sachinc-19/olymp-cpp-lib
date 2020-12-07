int inv_mod(int a, int m){
	assert(0<a);
	assert(a<m);
	return a==1 ? 1 : m-m*int64_t(inv_mod(m%a, a))/a;
}

const int mod = 998'244'353 ;
struct mint {
	int x;
	mint(): x(0) {}
	mint(const auto &val): x(val%mod) { if(x<0) x+=mod; }
};

bool operator==(const mint &a, const mint &b){ return a.x==b.x; }
bool operator!=(const mint &a, const mint &b){ return a.x!=b.x; }
void operator+=(mint &a, const mint &b){ a.x+=b.x; if(a.x>=mod) a.x-=mod; }
mint operator+(mint a, const mint &b){ a+=b; return a; }
void operator-=(mint &a, const mint &b){ a.x-=b.x; if(a.x<0) a.x+=mod; }
mint operator-(mint a, const mint &b){ a-=b; return a; }
void operator*=(mint &a, mint b){ a.x = int64_t(a.x)*b.x %mod; }
mint operator*(mint a, const mint &b){ a*=b; return a; }
void operator/=(mint &a, const mint &b){ a.x = int64_t(a.x)*inv_mod(b.x,mod) %mod; }
mint operator/(mint a, const mint &b){ a/=b; return a; }
mint operator-(mint a){ if(a.x) a.x = mod - a.x; return a; }
mint operator""m(unsigned long long x){ return mint(x); }
ostream& operator<<(ostream &o, const mint &m){ return o<<m.x; }

mint mpow(mint a, uint64_t n){
	mint res = 1;
	for(; n; n>>=1, a*=a) if(n&1) res*=a;
	return res;
}

