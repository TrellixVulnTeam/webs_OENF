// Ki thu?t th�m 1 node p v�o tru?c node q trong danh s�ch
#include<iostream>
using namespace std;

int n = 0; // khai bao bien toan cuc - chua toan bo phan tu trong danh sach

// Nh?p danh s�ch ki�n k?t don c�c s? nguy�n
// ============ KHAI B�O C?U TR�C DANH S�CH LI�N K?T �ON ============
struct node
{
	int data; // d? li?u c?a 1 node
	struct node *pNext; // con tr? d�ng d? li�n k?t gi?a c�c node v?i nhau
};
typedef struct node NODE;

// khai b�o c?u tr�c danh s�ch li�n k?t don
struct list
{ 
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;
// ============ KH?I T?O C?U TR�C DANH S�CH LI�N K?T �ON ===========
void KhoiTaoDSLK(LIST &l)
{
	// cho 2 node d?u v� cu?i tr? d?n v�ng nh? r?ng
	l.pHead = NULL;
	l.pTail = NULL;
}

// h�m kh?i t?o 1 c�i node
NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = x; // g�n x cho data
	p->pNext = NULL;
	return p;
}


// h�m th�m node p v�o d?u danh s�ch
void ThemVaoDau(LIST &l, NODE *p)
{
	// danh s�ch dang r?ng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead; // d�ng con tr? c?a node p li�n k?t v?i l.pHead
		l.pHead = p; // c?p nh?t l?i l.pHead l� p
	}
}

// h�m th�m node p v�o cu?i danh s�ch
void ThemVaoCuoi(LIST &l, NODE *p)
{
	// danh s�ch dang r?ng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p; // c?p nh?t l?i l.pTail l� p
	}
}

// xu?t danh s�ch li�n k?t don
void XuatDanhSach(LIST l)
{
	// for(int i = 0; i < n; i++)
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << "  ";
	}
}

// Th�m node p v�o sau node q(n?m trong danh s�ch li�n k?t don)
void ThemNode_p_VaoSauNode_q(LIST &l, NODE *p)
{
	int x;
	cout << "\nNhap gia tri node q: ";
	cin >> x;
	NODE *q = KhoiTaoNode(x);

	// n?u danh s�ch ch? c� 1 ph?n t? v� ph?n t? d� cung ch�nh l� node q ==> b�i to�n tr? th�nh ki thu?t th�m v�o cu?i danh s�ch
	if (q->data == l.pHead->data && l.pHead->pNext == NULL)
	{
		ThemVaoCuoi(l, p);
	}
	else
	{
		// duy?t t? d?u danh s�ch d?n cu?i danh s�ch d? t�m node q
		for (NODE *k = l.pHead; k != NULL; k = k->pNext)
		{
			// n?u node q c� t?n t?i th�....
			if (q->data == k->data)
			{
				NODE *h = KhoiTaoNode(p->data); // kh?i t?o node h m?i d? th�m v�o sau node q 
				NODE *g = k->pNext; // cho node g tr? d?n node n?m sau node q
				h->pNext = g; // Bu?c 1: T?o m?i li�n k?t t? node h d?n node g <=> cung ch�nh l� t?o m?i li�n k?t t? node h d?n node n?m sau node q
				k->pNext = h; // Bu?c 2: T?o m?i li�n k?t t? node q d?n node h <=> ch�nh l� node k d?n node h
			}
		}
	}
}

// Th�m node p v�o tru?c node q(n?m trong danh s�ch li�n k?t don)
void ThemNode_p_VaoTruocNode_q(LIST &l, NODE *p)
{
	int x;
	cout << "\nNhap gia tri node q: ";
	cin >> x;
	NODE *q = KhoiTaoNode(x); // kh?i t?o 1 node q

	// n?u danh s�ch ch? t?n t?i duy nh?t 1 node v� node n�y cung ch�nh l� node q lu�n - th� v?n d? tr? v? b�i to�n th�m node p v�o d?u danh s�ch
	if (q->data == l.pHead->data && l.pHead->pNext == NULL)
	{
		ThemVaoDau(l, p); // th�m node p v�o d?u danh s�ch
	} else {
		// ============ C�CH 1: TRONG DANH S�CH CH? T?N T?I 1 NODE Q ============
		//NODE *g = new NODE; // node g ch�nh l� node gi? li�n k?t v?i c�i node n?m tru?c node q trong danh s�ch
		//// duy?t danh s�ch t? d?u d?n cu?i d? t�m node q
		//for (NODE *k = l.pHead; k != NULL; k = k ->pNext)
		//{
		//	// ph�t hi?n node q c� t?n t?i trong danh s�ch th� b?t d?u th�m node p v�o tru?c node q
		//	if (q->data == k->data)
		//	{
		//		// th?c hi?n b�i to�n th�m node p v�o sau node g l� ra v?n d? <=> th�m node p v�o tru?c node q
		//		p->pNext = k; // Bu?c 1: cho node p tr?(li�n k?t) d?n node k <=> cung ch�nh l� cho node p tr? d?n node q
		//		g->pNext = p; // Bu?c 2: cho node g tr? d?n node p 
		//	}
		//	g = k; // gi? li�n k?t v?i c�i node n?m tru?c node q trong danh s�ch
		//}

		// ============ C�CH 2: TRONG DANH S�CH T?N T?I T? 2 NODE Q TR? L�N ============
		NODE *g = new NODE; // node g ch�nh l� node gi? li�n k?t v?i c�i node n?m tru?c node q trong danh s�ch
		// duy?t danh s�ch t? d?u d?n cu?i d? t�m node q
		for (NODE *k = l.pHead; k != NULL; k = k ->pNext)
		{
			// ph�t hi?n node q c� t?n t?i trong danh s�ch th� b?t d?u th�m node p v�o tru?c node q
			if (q->data == k->data)
			{
				NODE *h = KhoiTaoNode(p->data); // m?i l?n ph�t hi?n 1 node q th� ta kh?i t?o 1 node p m?i <=> kh?i t?o node h
				// th?c hi?n b�i to�n th�m node p v�o sau node g l� ra v?n d? <=> th�m node p v�o tru?c node q
				h->pNext = k; // Bu?c 1: cho node h tr?(li�n k?t) d?n node k <=> cung ch�nh l� cho node h tr? d?n node q
				g->pNext = h; // Bu?c 2: cho node g tr? d?n node h 
			}
			g = k; // gi? li�n k?t v?i c�i node n?m tru?c node q trong danh s�ch
		}
		if(q->data == l.pHead->data) {
			ThemVaoDau(l, p);
		}
	}
}

// h�m th�m 1 node p v�o 1 v? tr� b�t k� trong danh s�ch
void ThemNode_p_VaoViTriBatKi(LIST &l, NODE *p, int vt) { 
    
    // danh sach dang rong
	if(l.pHead == NULL || vt == 1) {
		// them node p vao dau
		ThemVaoDau(l,p);
	} else if(vt == n+1) {
		// them node p vao cuoi
		ThemVaoCuoi(l,p);
	} else {
		int dem = 0; // xac dinh vt can them
		NODE *g = new NODE; // node g ch�nh l� node gi? li�n k?t v?i c�i node n?m tru?c node q trong danh s�ch
		// duy?t danh s�ch t? d?u d?n cu?i d? t�m node q <=> tim ra cai vi tri can them node p vao
		for (NODE *k = l.pHead; k != NULL; k = k ->pNext)
		{
			dem++;
			// tim vi tri vt can them
			if (dem == vt)
			{
				NODE *h = KhoiTaoNode(p->data); // m?i l?n ph�t hi?n 1 node q th� ta kh?i t?o 1 node p m?i <=> kh?i t?o node h
				// th?c hi?n b�i to�n th�m node p v�o sau node g l� ra v?n d? <=> th�m node p v�o tru?c node q
				h->pNext = k; // Bu?c 1: cho node h tr?(li�n k?t) d?n node k <=> cung ch�nh l� cho node h tr? d?n node q
				g->pNext = h; // Bu?c 2: cho node g tr? d?n node h 
				break;
			}
			g = k; // gi? li�n k?t v?i c�i node n?m tru?c node q trong danh s�ch
		}
	}
}

void XoaDau(LIST &l) {
	if(l.pHead == NULL) {
		return;
	} 
	NODE *p = l.pHead; // Node p la node se xoa
	l.pHead = l.pHead->pNext; // cap nhat lai l.pHead la phan tu ke tiep
	delete p;
}

void XoaCuoi(LIST &l) {
	if(l.pHead == NULL) {
		return;
	}
	// truong hop danh sach co 1 phan tu
	if(l.pHead->pNext == NULL) {
		XoaDau(l);
		return;
	}
	for(NODE *k = l.pHead; k != NULL; k = k->pNext) {
		// phat hien thang ke cuoi
		if(k->pNext == l.pTail) {
			delete l.pTail; 
			k->pNext = NULL;
			l.pTail = k; // cap nhat lai l.ptail
			return;
		}
	}
	
}

// ham xoa 1 node nam sau node q trong danh sach
void XoaSauNODE_q(LIST &l, NODE *q) {
	// duyet danh sach tu dau den den cuoi de tim node q
	for(NODE *k = l.pHead; k != NULL; k = k->pNext) {
		if(k->data == q->data) {
			NODE *g = k->pNext; // node g la nod nam sau node k <=> la node ma ta se xoa
	        k->pNext = g->pNext; // cap nhat moi lien ket
	        delete g; // xoa node nam sau node q
	        return;
		}
	}
}
//void XoaTruocNode_q(LIST &l, NODE *q) {
//	for(NODE *k = l.pHead; k != NULL; k = k->pNext) {
//		
//		if(k->data == q->data) {
//			NODE *g = k->pNext; // node g la nod nam sau node k <=> la node ma ta se xoa
//	        k->pNext = g->pNext; // cap nhat moi lien ket
//	        delete g; // xoa node nam sau node q
//	        return;
//		}
//	}
//}

void XoaTaiViTriBatKi(LIST &l, int vt) {
	if(vt == 1) {
		XoaDau(l);
	} else if(vt == n+1) {
		XoaCuoi(l);
	} else {
		int dem = 1;
		for(NODE *k = l.pHead; k != NULL; k = k->pNext) {
			dem++;
			if(dem == vt) {
				NODE *h = k->pNext;
				k->pNext = h->pNext;
				delete h;
				return;
			}
		}
	}
}

// giai phong vung nho cho danh sach lien ket don
void Giai_Phong_Danh_Sach(LIST &l) {
	NODE *k = NULL;
	while(l.pHead != NULL) {
		k = l.pHead;
		l.pHead = l.pHead->pNext;
		delete k;
	}
}


// menu
void Menu(LIST &l)
{
	int luachon;
	while (69)
	{
		system("cls");
		cout << "\n\n\t\t========== Menu ==========";
		cout << "\n\t1. Them node vao danh sach";
		cout << "\n\t2. Xuat danh sach lien ket don";
		cout << "\n\t3. Them node p vao sau node q trong danh sach";
		cout << "\n\t4. Them node p vao truoc node q trong danh sach";
		cout << "\n\t5. Them node p vao vi tri bat ki trong danh sach";
		cout << "\n\t6. Xoa dau";
		cout << "\n\t7. Xoa cuoi";
		cout << "\n\t8. Xoa node sau node q";
		cout << "\n\t9. Xoa tai mot vi tri bat ki";
		cout << "\n\t0. Thoat";
		cout << "\n\n\t\t========== End ===========";

		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon < 0 || luachon > 9)
		{
			cout << "\nLua chon khong hop le. Xin kiem tra lai !";
			system("pause"); // d?ng m�n h�nh
		}
		else if (luachon == 1)
		{
			n++;
			int x;
			cout << "\nNhap gia tri so nguyen: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x); // kh?i t?o 1 c�i node
			ThemVaoCuoi(l, p); // th�m node v�o cu?i danh s�ch
		}
		else if (luachon == 2)
		{
			XuatDanhSach(l);
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			cout << "\nNhap gia tri node p can them vao sau: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);
			ThemNode_p_VaoSauNode_q(l, p); // th�m node p v�o sau node q trong danh s�ch l
			n++;
		}
		else if (luachon == 4)
		{
			n++;
			int x;
			cout << "\nNhap gia tri node p can them vao truoc: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);
			ThemNode_p_VaoTruocNode_q(l, p); // th�m node p v�o tru?c node q trong danh s�ch l
		}
		else if(luachon == 5) {
			// khoi tao gia tri cho node p
			int x;
			cout << "\nNhap gia tri node p: ";
			cin >> x;
			
			NODE *p = KhoiTaoNode(x);
			// nhap vi tri can them cho node p ==> can kiem tra dieu kien
			int vt;
			do {
				cout << "\nNhap vi tri can them node p: ";
				cin >> vt;
				if(vt < 1 || vt > n+1) {
					cout << "\nVitri can them phai nam trong doan[1; " << n+1 << "]";			}
			} while(vt < 1 || vt > n + 1);
			ThemNode_p_VaoViTriBatKi(l,p,vt);
			n++;
		}
		else if(luachon == 6) 
		{
			XoaDau(l);
			n--;
		}
		else if(luachon==7) {
			XoaCuoi(l);
			n--;
		}
		else if(luachon == 8){
			int x;
			cout << "\nNhap node q: ";
			cin >> x;
			NODE *q = KhoiTaoNode(x);
			XoaSauNODE_q(l,q);
			n--;
		} else if(luachon == 9) {
			int x;
			cout << "\nNhap vi tri can xoa;";
			cin >> x;
			XoaTaiViTriBatKi(l,x);
		}
		else
		{
			break; // tho�t kh?i v�ng l?p hi?n t?i
		}
	}
}

int main()
{
	LIST l;
	KhoiTaoDSLK(l); // lu�n lu�n g?i h�m kh?i t?o danh s�ch li�n k?t don tru?c khi thao t�c v?i danh s�ch
	Menu(l);

	system("pause");
	return 0;
}
