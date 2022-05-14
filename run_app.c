#include<stdio.h>
#include<limits.h>
#include<math.h>
#include<float.h>
#include<string.h>
void type() {
	int a = 0;
	double b = 0.11;
	float c = 0.11;
	int* p = &a;
	char ch = 97;
	printf("int a= %d,double b=%f,float c=%f,int* p=%d,char ch=%c\n",a,b,c,*p,ch);
	//int ��Χ-2147483648��2147483647��-2^{31} \sim 2^{31}-1��
	printf("INT_MAX=%d,INT_MIN%d\n", INT_MAX,INT_MIN);
	//���
	printf("INT_MAX+1=%d,INT_MIN-1=%d\n", INT_MAX+1, INT_MIN-1);
}
void type_len() {
	printf("char is take %llu byte\n",sizeof(char));
	printf("short is take %llu byte\n",sizeof(short));
	printf("int is take %llu byte\n",sizeof(int));
	printf("long is take %llu byte\n",sizeof(long));
	printf("long long is take %llu byte\n",sizeof(long long));
	printf("float is take %llu byte\n",sizeof(float));
	printf("double is take %llu byte\n",sizeof(double));
}
void input_char() {
	//���-128��ʾchar�ڱ������з��ŵ�
	//���0��ʾchar���޷��ŵ�
	printf("CHAR_MIN=%d\n",CHAR_MIN); 
	char c;
	while ((c=getchar())!=EOF)
	{
		printf("c=%c\n",c);
	}
}
//�Ƚϸ�����
void compare_float() {
	float a = 0.33f;
	float b = 0.11f;
	b += 0.22f;
	//�����
	if (a == b) {
		printf("a==b is true\n");
	}
	if (fabs(b - a) < FLT_EPSILON) {
		printf("a==b is true\n");
	}
}
//�Ƚ��ַ�������
void compare_str_len() {
	char str1[] = "abcdefg";
	char str2[] = "abc";
	//��� true
	if (strlen(str2)-strlen(str1)>0) {
		printf("strlen(str2)-strlen(str1)>0 \n");
	}
	if (strlen(str2) > strlen(str1)) {
		printf("strlen(str2) > strlen(str1) \n");
	}
}

// array length
void arr_len() {
	int a[] = { 0,1,2,3,4,5 };
	char c[] = { 'a','b' };
	int* ip = a;
	char* cp = c;
	printf("sizeof(ip)=%llu\n,sizeof(cp)=%llu\n",sizeof(ip),sizeof(cp));
	//int 4�ֽ� char 1�ֽ�
	printf("sizeof(a)=%llu\n,sizeof(c)=%llu\n",sizeof(a),sizeof(c));
}
int main() {
	type();
	type_len();
	//input_char();
	compare_float();
	compare_str_len();
	arr_len();
	return 0;
}
