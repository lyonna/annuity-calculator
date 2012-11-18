/*
 * 作品名称：年金计算器
 * 版本：1.4
 * 作者：t@lyonna.me
 * 日期：2012-11-17 19:57
 * 许可协议：GPLv2
 *
 * Windows/Linux/Android等环境下均可直接编译，编译前注意编码转换
 * 当前使用UTF-8编码，Unix换行符
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#ifdef WIN32
#define CLS system("cls");
#else
#define CLS system("clear");
#endif

char str[][40] = {
  "===== 年金计算器 V1.4 =====",
  "01 已知名义利率，算实际利率",
  "02 一次支付：知本金，算终值",
  "03 一次支付：知终值，算现值",
  "04 普通年金：知年金，算终值",
  "05 普通年金：知年金，算现值",
  "06 普通年金：知终值，算年金",
  "07 普通年金：知现值，算年金",
  "08 先付年金：知年金，算终值",
  "09 先付年金：知年金，算现值",
  "10 先付年金：知终值，算年金",
  "11 先付年金：知现值，算年金",
  "12 递延年金：知年金，算终值",
  "13 递延年金：知年金，算现值",
  "14 递延年金：知终值，算年金",
  "15 递延年金：知现值，算年金",
  "16 永续年金：知年金，算现值",
  "17 永续年金：知现值，算年金",
  "18 退出",
  "选择一项：",
  "输入错误！",
  "按回车键返回菜单..."
};

float iof(char c) {
  float n;
  switch(c) {
    case 'a': printf("年    金："); scanf("%f", &n); break;
    case 'p': printf("现    值："); scanf("%f", &n); break;
    case 'f': printf("终    值："); scanf("%f", &n); break;
    case 'r': printf("利 率(%%)："); scanf("%f", &n); break;
    default: n=0; break;
  }
  return n;
}

int iod(char c) {
  int n;
  switch(c) {
    case 'n': printf("期    数："); scanf("%d", &n); break;
    case 'm': printf("递延期数："); scanf("%d", &n); break;
    case 'd': printf("总 期 数："); scanf("%d", &n); break;
    default: n=0; break;
  }
  return n;
}

int pr(char c, float n) {
  switch(c) {
    case 'a': printf("年    金：%.4f元\n", n); break;
    case 'p': printf("期初现值：%.4f元\n", n); break;
    case 'f': printf("期末终值：%.4f元\n", n); break;
    default: break;
  }
  return 0;
}

int i2i() {
  float r;
  int t;
  printf("名义利率(%%)：");
  scanf("%f", &r);
  printf("计 息 次 数：");
  scanf("%d", &t);
  printf("实际利率(%%)：%f\n", (pow(1+r/100/t, t)-1)*100);
  return 0;
}

int p2f() {
  float p,r;
  int n;
  p=iof('p');
  r=iof('r');
  n=iod('n');
  pr('f', p*pow((1+r/100), n));
  return 0;
}

int f2p() {
  float f,r;
  int n;
  f=iof('f');
  r=iof('r');
  n=iod('n');
  pr('p', f/pow((1+r/100), n));
  return 0;
}

int a2f() {
  float a,r;
  int n;
  a=iof('a');
  r=iof('r');
  n=iod('n');
  pr('f', a*(pow((1+r/100), n)-1)/r*100);
  return 0;
}

int a2p() {
  float a,r;
  int n;
  a=iof('a');
  r=iof('r');
  n=iod('n');
  pr('p', a*(1-1/pow((1+r/100), n))/r*100);
  return 0;
}

int f2a() {
  float f,r;
  int n;
  f=iof('f');
  r=iof('r');
  n=iod('n');
  pr('a', f/((pow((1+r/100), n)-1)/r*100));
  return 0;
}

int p2a() {
  float p,r;
  int n;
  p=iof('p');
  r=iof('r');
  n=iod('n');
  pr('a', p/((1-1/pow((1+r/100), n))/r*100));
  return 0;
}

int ba2f() {
  float a,r;
  int n;
  a=iof('a');
  r=iof('r');
  n=iod('n');
  pr('f', a*(pow((1+r/100), n)-1)/r*100*(1+r/100));
  return 0;
}

int ba2p() {
  float a,r;
  int n;
  a=iof('a');
  r=iof('r');
  n=iod('n');
  pr('p', a*(1-1/pow((1+r/100), n))/r*100*(1+r/100));
  return 0;
}

int bf2a() {
  float f,r;
  int n;
  f=iof('f');
  r=iof('r');
  n=iod('n');
  pr('a', f/((pow((1+r/100), n)-1)/r*100*(1+r/100)));
  return 0;
}

int bp2a() {
  float p,r;
  int n;
  p=iof('p');
  r=iof('r');
  n=iod('n');
  pr('a', p/((1-1/pow((1+r/100), n))/r*100*(1+r/100)));
  return 0;
}

int da2f() {
  float a,r;
  int n,m;
  a=iof('a');
  r=iof('r');
  m=iod('m');
  n=iod('d');
  pr('f', a*(pow((1+r/100), n-m)-1)/r*100);
  return 0;
}

int da2p() {
  float a,r;
  int n,m;
  a=iof('a');
  r=iof('r');
  m=iod('m');
  n=iod('d');
  pr('p', a*(((1-1/pow((1+r/100), n))/r*100)-((1-1/pow((1+r/100), m))/r*100)));
  return 0;
}

int df2a() {
  float f,r;
  int n,m;
  f=iof('f');
  r=iof('r');
  m=iod('m');
  n=iod('d');
  pr('a', f/((pow((1+r/100), n-m)-1)/r*100));
  return 0;
}

int dp2a() {
  float p,r;
  int n,m;
  p=iof('p');
  r=iof('r');
  m=iod('m');
  n=iod('d');
  pr('a', p/(((1-1/pow((1+r/100), n))/r*100)-((1-1/pow((1+r/100), m))/r*100)));
  return 0;
}

int ya2p() {
  float a,r;
  a=iof('a');
  r=iof('r');
  pr('p', a/r*100);
  return 0;
}

int yp2a() {
  float p,r;
  p=iof('p');
  r=iof('r');
  pr('a', p*r/100);
  return 0;
}

int menu() {
  CLS
  int s,i;
  for(i=0; i<20; i++) {
    printf("%s", str[i]);
  switch(i) {
    case 0: puts("\n"); break;
    case 18: puts("\n"); break;
    case 19: break;
    default: putchar(10); break;
  }
  }
  scanf("%d", &s);
  if(s==18) {
    exit(0);
  }
  CLS
  printf("%s\n\n%s\n\n", str[0], str[s]);
  switch(s) {
    case 1: i2i(); break;
    case 2: p2f(); break;
    case 3: f2p(); break;
    case 4: a2f(); break;
    case 5: a2p(); break;
    case 6: f2a(); break;
    case 7: p2a(); break;
    case 8: ba2f(); break;
    case 9: ba2p(); break;
    case 10: bf2a(); break;
    case 11: bp2a(); break;
    case 12: da2f(); break;
    case 13: da2p(); break;
    case 14: df2a(); break;
    case 15: dp2a(); break;
    case 16: ya2p(); break;
    case 17: yp2a(); break;
    default: printf("%s\n", str[20]);
  }
  printf("\n%s", str[21]);
  getchar();
  getchar();
  return 0;
}

int main() {
  do {
    menu();
  } while(1);
  return 0;
}
