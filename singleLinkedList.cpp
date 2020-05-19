#include<stdio.h>
#include<string.h>
typedef char infor1[20];
typedef float infor2;
typedef float infor3;
struct element {
	infor1 name;
	infor2 height;
	infor3 weight;
	element *next;
};

typedef element *List;

void menu() {
	printf("\n==========================================\n");
	printf(" Chon chuc nang \n");
	printf("0. Exit \n");
	printf("1. Them phan tu moi \n");
	printf("2. Hien thi\n");
	printf("3. Tim phan tu dau tien theo ten\n");
	printf("4. Tim tat ca theo ten \n");
	printf("5. Xoa nguoi dau tien \n");
	printf("6. Xoa nguoi dau tien tim duoc theo ten \n");
	printf("7. Xoa tat ca nhung nguoi tim duoc theo ten \n");
	printf("8. Tinh tong chieu cao \n");
	printf("9. Tinh tong chieu cao cao hon tieu chuan \n");
	printf("\n==========================================\n");
}

void Create(List &F) {
	F = NULL;
}

void Display(List F) {
	List p = F;
	while (p != NULL) {
		printf("%s\t%.2f\t%.2f\n",(*p).name,(*p).height,(*p).weight);
		p = (*p).next;
	}
}

void InsertFirst(List &F, infor1 name, infor2 height) {
	List p = new element;
	strcpy((*p).name, name);
	(*p).height = height;
	(*p).weight = height * 100 - 105;
	(*p).next = F;
	F = p;
}

List Search(List F, infor1 key) {
	List p;
	p = F;
	while (p != NULL && strcmp((*p).name, key) != 0) {
		p = (*p).next;
	}
	return p;
}

void SearchAll(List F, infor1 key) {
	List p;
	p = F;
	while (p != NULL) {
		if (strcmp((*p).name, key) == 0) {
			printf("%s\t%.2f\t%.2f\n",(*p).name,(*p).height,(*p).weight);
		}
		p = (*p).next;
	}
}

void DeleteFirst(List &F) {
	List p;
	if (F != NULL) {
		p = F;
		F = (*p).next;
		delete p;		
	}
}

void DeleteElement(List &F, List p) {
	List before, after;
	after = F;
	while (after != NULL && after != p) {
		before = after;
		after = (*after).next;
	}
	if (after != NULL) {
		if (F == p) {
			F = (*p).next;
		}
		else {
			(*before).next = (*p).next;
		}
		delete p;
	}
}

void SearchAndDelete(List &F, infor1 name) {
	List key = Search(F, name);
	DeleteElement(F, key);
}

void SearchAndDeleteAll(List &F, infor1 name) {
	List p;
	do {
		p = Search(F, name);
		DeleteElement(F, p);
	} while (p != NULL);
}

float HeightSum(List F) {
	float sum = 0;
	List p = F;
	while (p != NULL) {
		sum += (*p).height;
		p = (*p).next;
	}
	return sum;
}

float HigherSum(List F, float standard) {
	float sum = 0;
	List p = F;
	while (p != NULL) {
		if((*p).height > standard) sum += (*p).height;
		p = (*p).next;
	}
	return sum;
}

int main() {
	List F;
	Create(F);
	int x;
	char check;
	do {
		menu();
		scanf("%d", &x);
		switch (x) {
			case 0: {
				break;
			}
			case 1: {
				infor1 name;
				infor2 height;
				infor3 weight;
				while(true) {
					fflush(stdin);
					printf("nhap ten (nhan enter neu muon bo qua): ");
					gets(name);
					if (name[0] == '\0') break;
					printf("chieu cao: ");
					scanf("%f", &height);
					InsertFirst(F, name, height);
				}
				break;
			}
			case 2: {
				Display(F);
				break;
			}
			case 3: {
				printf("nhap ten can tim: ");
				infor1 key;
				fflush(stdin);
				gets(key);
				List p = Search(F, key);
				if(p == NULL) printf("khong tim thay \n");
				printf("%s\t%.2f\t%.2f\n",(*p).name,(*p).height,(*p).weight);
				break;
			}
			case 4: {
				infor1 key;
				printf("nhap ten can tim: ");
				fflush(stdin);
				gets(key);
				SearchAll(F, key);
				break;
			}
			case 5: {
				DeleteFirst(F);
				break;
			}
			case 6: {
				infor1 key;
				printf("\n nhap ten can xoa: ");
				fflush(stdin);
				gets(key);
				SearchAndDelete(F, key);
				break;
			}
			case 7: {
				infor1 key;
				printf("\n nhap ten can xoa: ");
				fflush(stdin);
				gets(key);
				SearchAndDeleteAll(F, key);
				break;
			}
			case 8: {
				printf("\ntong chieu cao: %.2f \n", HeightSum(F));
				break;
			}
			case 9: {
				float standard;
				printf("nhap chieu cao tieu chuan: ");
				scanf("%f", &standard);
				printf("\n tong chieu cao: %.2f \n", HigherSum(F,standard));
				break;
			}
			default: break;
		}
		printf("goto menu (y/n): ");
		fflush(stdin);
		scanf("%c", &check);
	} while (check != 'n');
	return 0;
}
