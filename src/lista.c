#include "lista.h"

//Técnica para swap de structs - algumas vezes não é seguro
void SwapStruct(void *a, void *b, size_t size) {
    if (a == b) return;

    unsigned char *pa = (unsigned char *)a;
    unsigned char *pb = (unsigned char *)b;

    for (size_t i = 0; i < size; i++) {
        pa[i] ^= pb[i];
        pb[i] ^= pa[i];
        pa[i] ^= pb[i];
    }
}

//Técnica utilizando XOR para variável numérica
void Swap(Item *a, Item *b){
    if (a != b) {
        a->val = a->val ^ b->val;
        b->val = a->val ^ b->val;
        a->val = a->val ^ b->val;
    }
}

// Técnica por troca de endereços
//void Swap(Item **a, Item **b){
//	Item *aux;
//	*aux = *a;
//	*a  = *b;
//	*b  = aux;
//}

// Técnica tradicional
//void Swap(Item *a, Item *b){
//	Item aux;
//	aux = *a;
//	*a  = *b;
//	*b  = aux;
//}

void FLVazia(Lista *l){
	l->first = 0;
	l->last  = 0;
}

bool FIsVazia(Lista *l){
	return l->first == l->last;
}

void LInsert(Lista *l, Item d){
	if (l->last >= MAXTAM){
		printf("LISTA CHEIA!\n");
	}else{
		l->vet[l->last] = d;
		l->last ++;
	}
}

void LRemove(Lista *l, Item d){
	bool ok = false;

	if(FIsVazia(l))
		printf("LISTA VAZIA!\n");
	else{
		for(int i=l->first; i<l->last; i++)
			if(l->vet[i].val == d.val){
				Swap(&l->vet[i], &l->vet[i+1]);
				//SwapStruct(&l->vet[i], &l->vet[i+1], sizeof(Item));
				ok = true;	
			}
	
		if(ok)
			l->last --;
	}
}


void LImprime(Lista *l){
	for(int i=l->first; i<l->last; i++)
		printf("%d\t", l->vet[i].val);
	printf("\n");
}

