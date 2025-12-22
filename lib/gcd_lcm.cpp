template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T, class... U> T gcd(T arg, U... args){ T res = arg; ((res = gcd(res, args)), ...); return res; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b ; }
template<class T, class... U> T lcm(T arg, U... args){ T res = arg; ((res = lcm(res, args)), ...); return res; }