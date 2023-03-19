#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	FILE* fo = fopen("sample1.bmp", "rb");
	FILE* fw = fopen("output.bmp", "wb");

	if (fo == NULL || fw == NULL) {
		printf("File open failed\n");
		return 1;

	}

	//���� ������
	fgetc(fo);
	fgetc(fo);

	int FILESIZE = 0;
	fread(&FILESIZE, sizeof(int), 1, fo);
	printf("Filesize: %d \n", FILESIZE);

	//5-9 BYTE �н�
	fgetc(fo); fgetc(fo); fgetc(fo); fgetc(fo);

	//�ȼ���ŸƮ���� �б�
	int PIXELSTART = 0;
	fread(&PIXELSTART, sizeof(int), 1, fo);
	printf("PIXELSTART: %d \n", PIXELSTART);

	rewind(fo);

	char c;
	//�ȼ����������� ��ŵ
	for (int i = 0; i < PIXELSTART; i++) {
		c = fgetc(fo);
		fputc(c, fw);
	}

	//�� �ȼ� ���̱�
	
	char r, g, b, avg;

	for (int i = PIXELSTART; i < FILESIZE;  i += 4) {
		r = fgetc(fo);
		g = fgetc(fo);
		b = fgetc(fo);
		avg = (r + g + b) / 3;
		char s = fgetc(fo);
	
		fwrite(&avg, 1, 1, fw);
		fwrite(&avg, 1, 1, fw);
		fwrite(&avg, 1, 1, fw);
		fwrite(&s, 1, 1, fw);
	}
	fclose(fo);
	fclose(fw);

	return 0;
}