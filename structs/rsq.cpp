template<class T>
struct rsq {
	explicit rsq(size_t n = 0): f(n) {}
	rsq(const vector<auto> &vals): f(size(vals)) {
		copy(begin(vals), end(vals), begin(f));
		for(size_t i = size(vals); i--;) if(size_t j = i&(i+1)) f[j-1]+=f[i];
	}
	void add(size_t i, const T &val) {
		for(++i; i--; i&=i+1) f[i]+=val;
	}
	T operator()(size_t l, size_t r) const {
		return l < r ? sum_suf(l) - sum_suf(r) : T{};
	}
	T operator[](size_t i) const { return sum_suf(i) - sum_suf(i+1); }
	T sum_suf(size_t i) const {
		T s{}; for(; i<size(f); i|=i+1) s+=f[i];
		return s;
	}
	private: valarray<T> f;
};
