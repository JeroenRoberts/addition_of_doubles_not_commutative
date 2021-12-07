#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <float.h>

void add_and_print(double* total, double a) {
    *total += a;
    printf("+\t%.*e, ", DECIMAL_DIG, a);
    printf("\ttotal: %.*e\n", DECIMAL_DIG, *total);
}
void dump(const void *data, size_t len) {
    const unsigned char *x = data;
    printf("%02x", x[0]);
    for (size_t k = 1; k < len; k++){ 
        printf(" %02x", x[k]);
    }
    puts("");
}

void printt(double a) {
    printf("%.*e,     %a\n", DECIMAL_DIG, a, a);
}
int main(){
//https://stackoverflow.com/questions/55930726/sscanf-fails-to-read-double-hex/55939590#55939590
//https://stackoverflow.com/questions/4738768/printing-double-without-losing-precision

    printf("Hello world\n");
    double total_one = 0;
    double total_two = 0;

    /* double a_100 = 1.293838152302690183704 * pow(10, -2); */
    /* printf("%.*e, \n", DECIMAL_DIG, a_100); */
    /* dump(& a_10, sizeof a_10); */
    /* double a_10 = -1.293838152302690183704 * pow(10, -2); */
    double a_10;
    sscanf("-0x1.a7f702c095ca2p-7", "%la", &a_10);
    double a_99;
    sscanf("0x1.a7f702c095c5fp-7", "%la", &a_99);
    double a_90;
    sscanf("0x1.a7f702c095ca2p-7", "%la", &a_90);
    double a_19;
    sscanf("-0x1.a7f702c095c5fp-7", "%la", &a_19);
    printt(a_10);
    printt(a_99);
    printt(a_90);
    printt(a_19);
    /* double a_10 = -1.293838152302690183704 * pow(10, -2); */
    /* double a_99 = 1.293838152302678561056 * pow(10, -2); */
    /* double a_90 = 1.293838152302690183704 * pow(10, -2); */
    /* double a_19 = -1.293838152302678561056 * pow(10, -2); */
    /* printt(a_99); */
    /* printt(a_90); */
    /* printt(a_19); */
    printf("\n\n");
    add_and_print(&total_one, 0);
    add_and_print(&total_one, a_10);
    add_and_print(&total_one, a_99);
    add_and_print(&total_one, a_90);
    add_and_print(&total_one, a_19);
    printf("\n\n");

    add_and_print(&total_one, 0);
    add_and_print(&total_two, a_10);
    add_and_print(&total_two, a_19);
    add_and_print(&total_two, a_90);
    add_and_print(&total_two, a_99);

    return 0;
}
