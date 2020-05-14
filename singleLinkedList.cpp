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

void Create(List &F) {
	F = NULL;
}

void Display(List F) {
	List p;
	p = F;
	while (p != NULL) {
		printf("%s \t %.2f \t %.2f \n", (*p).name, (*p).height, (*p).weight);
		p = (*p).next;
	}
}

void InsertFirst(List &F, infor1 name, infor2 height) {
	infor3 weight;
	List p = new element;
	strcpy((*p).name, name);
	(*p).height = height;
	(*p).weight = height * 100 - 105;
	(*p).next = F;
	F = p;
}

List Search(List F) {
	infor1 nameNeedSearch;
	scanf("%s", &nameNeedSearch);
	List p;
	p = F;
	while ((p != NULL) && strcmp((*p).name, nameNeedSearch) != 0) {
		p = (*p).next;
	}
	return p;
}

List SearchAll(List F) {
	infor1 nameNeedSearch;
	printf("nhap ten can tim: ");
	scanf("%s", &nameNeedSearch);
	List p;
	p = F;
	while (p != NULL) {
		if (strcmp((*p).name, nameNeedSearch) == 0) {
			printf("%s \t %.2f \t %.2f \n", &(*p).name, (*p).height, (*p).weight);
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
	List before,after;
	after = F;
	while (after != NULL && after != p) {
		before = after;
		after = (*after).next;
	}
	if(after != NULL) {
		if (F == p) {
			F = (*p).next ;
		}
		else {
			(*before).next = (*p).next;
		}
		delete p;
	}
}

void SearchAndDelete(List &F) {
	List p = Search(F);
	DeleteElement(F, p);
}

//void SearchAndDeleteAll(List &F) {
//	List p = Search(F);
//	do {
//		List p = Search(F);
//		DeleteElement(F, p);
//	} while (p != NULL);
//}

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
		if((*p).height >= standard) sum += (*p).height;
		p = (*p).next;
	}
	return sum;
}

void menu() {
	printf("\n==========================================\n");
	printf("chon chuc nang: \n");
	printf("0. Exit \n");
	printf("1. Them phan tu vao dau danh sach \n");
	printf("2. Hien thi \n");
	printf("3. Tim kiem phan tu xuat hien dau tien \n");
	printf("4. tim kiem tat ca \n");
	printf("5. Xoa phan tu dau danh sach \n");
	printf("6. Tim kiem va xoa phan tu dau tien \n");
	printf("7. Tim kiem va xoa tat ca \n");
	printf("8. Tinh  tong chieu cao \n");
	printf("9. Tinh  tong chieu cao lon hon \n");
	printf("\n==========================================\n");
}

int main() {
	List F;
	Create(F);
	char check;
	do {
		menu();
		int x;
		scanf("%d",&x);
		switch (x) {
			case 0: {
				break;
			}
			case 1: {
				while (true) {
					infor1 name;
					infor2 height;
					fflush(stdin);
					printf("nhap ten: ");
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
				List p = Search(F);
				if(p == NULL) {
					printf("khong tim thay!!!");
				}
				printf("%s \t %.2f \t %.2f \n", (*p).name, (*p).height, (*p).weight);
				break;
			}
			case 4: {
				SearchAll(F);
				break;
			}
			case 5: {
				DeleteFirst(F);
				break;
			}
			case 6: {
				printf("nhap ten can xoa: ");
				SearchAndDelete(F);
				break;
			}
			case 7: {
				printf("nhap ten can xoa: ");
				//SearchAndDeleteAll(F);
				break;
			}
			case 8: {
				printf("\ntong chieu cao: %.2f", HeightSum(F));
				break;
			}
			case 9: {
				float standard;
				printf("nhap chieu cao tieu chuan: ");
				scanf("%f", &standard);
				printf("\n tong chieu cao: %.2f", HigherSum(F,standard));
				break;
			}
			default: break;
		}
		printf("\n goto menu(y/n): ");
		fflush(stdin);
		scanf("%c",&check);
	} while(check != 'n');
	return 0;
}
