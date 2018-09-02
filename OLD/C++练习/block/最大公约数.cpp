
/*************最大公约数*******************/
typedef unsigned long long LL;
LL gcd(LL a, LL b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}