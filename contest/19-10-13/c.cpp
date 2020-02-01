/*   _ _ _                     
    | | | | ___  ___           
    | | | || . ||  _|          
    |_____||_  ||_|  _____     
             |_|    |_____|  */
// Time : 19/10/13
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define inf 0x3f3f3f3f
#define iofuck std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int nmax = 1000 + 10;
double getc(double _a, double _b) {
  double a = _a + _b;
  double b = max(_b, _a) - min(_b, _a);
  double c = sqrt(a * a - b * b);
  return c;
}
int n;
double r[nmax];
void test() {
  vector<int> v;
  double minn = 10000;
  do {
    double ans = r[0] + r[n - 1];
    /*
        for(int i = 0; i < n; i++){
            cout << r[i] << " ";
        }
        cout << "->";
        */
    for (int i = 1; i < n; i++) {
      ans += getc(r[i - 1], r[i]);
    }
    if (ans < minn) {
      minn = ans;
      v.clear();
      for (int i = 0; i < n; i++) {
        v.push_back(r[i]);
      }
    }
  } while (next_permutation(r, r + n));
  for (auto i: v) {
    cout << i << " ";
  }
  cout << "->";
  cout << minn << endl;
}
int main() {
#ifdef Wqr_
  freopen("in.txt", "r", stdin);
#endif
  double ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> r[i];
  if (n == 1) {
    cout << r[0] * 2 << endl;
    return 0;
  }
  sort(r, r + n);
  //test();
  list<double> li;
  li.push_back(r[0]);
  int itl = 0, itr = n;
  bool ifda = 1;
  int ci = 0;
  for (int i = 1; i < n; i++) {
    if (ifda) {
      if (ci == 0) {
        li.push_back(r[--itr]);
        ci++;
      } else if (ci == 1) {
        li.push_front(r[--itr]);
        ci++;
      }
      if (ci == 2) {
        ifda = !ifda;
        ci = 0;
      }
    } else {
      if (ci == 0) {
        li.push_back(r[++itl]);
        ci++;
      } else if (ci == 1) {
        li.push_front(r[++itl]);
        ci++;
      }
      if (ci == 2) {
        ifda = !ifda;
        ci = 0;
      }
    }
  }
  vector<double> v;

  for (auto i: li) {
    //cout << i << " ";
    v.push_back(i);
  }
  ans += *v.begin() + v.back();

  for (int i = 1; i < v.size(); i++) {
    ans += getc(v[i], v[i - 1]);
  }
  double ans2 = 0;

  li.clear();
  v.clear();
  li.push_back(r[n - 1]);
  itr = n - 1, itl = -1;
  ifda = 0;
  ci = 0;
  for (int i = 1; i < n; i++) {
    if (ifda) {
      if (ci == 0) {
        li.push_back(r[--itr]);
        ci++;
      } else if (ci == 1) {
        li.push_front(r[--itr]);
        ci++;
      }
      if (ci == 2) {
        ifda = !ifda;
        ci = 0;
      }
    } else {
      if (ci == 0) {
        li.push_back(r[++itl]);
        ci++;
      } else if (ci == 1) {
        li.push_front(r[++itl]);
        ci++;
      }
      if (ci == 2) {
        ifda = !ifda;
        ci = 0;
      }
    }
  }
  for (auto i: li) {
    v.push_back(i);
  }
  ans2 += *v.begin() + *v.rbegin();
  for (int i = 1; i < n; i++) {
    ans2 += getc(v[i], v[i - 1]);
  }
  printf("%.6f\n", min(ans, ans2));
  return 0;
}