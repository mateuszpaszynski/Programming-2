#include <iostream>
using namespace std;
using BYTE = unsigned char;
BYTE SIZE = 4;
using OBJECT_TYPE = int;
struct NODE_STRUCT {
    OBJECT_TYPE* object;
    NODE_STRUCT* next;
    BYTE use;
};
void printA(NODE_STRUCT* head,int a = 0)
{
    if (head==NULL) {
        cout<<"NULL"<<endl;
        return;
    }
    printf("tab[%d]=%d : ",a,head->use);
    for ( int i = 0;i<head->use;i++)
        cout<<head->object[i]<<" ";
    cout<<endl;
    if (head->next !=NULL) {
        printA(head->next,a+1);
    }
    else {
        cout<<"--------------\n";
    }

}
void print(NODE_STRUCT*obiekt) {
    if ( obiekt == NULL) {
        cout<<"NULL"<<endl;
        return;
    }
    cout<<"obiekt : "<<obiekt<<endl;
    cout<<"use : "<<obiekt->use+0<<endl;
    cout<<"next : "<<obiekt->next<<endl;
    cout<<"obiekty : ";
    for ( int i = 0;i<obiekt->use;i++) {
      cout<<obiekt->object[i]<<" ";
    }
    cout<<endl;
}
//Mateusz Paszynski
NODE_STRUCT* NewNode() {
    NODE_STRUCT* nowy = new NODE_STRUCT;
    nowy->object =  new OBJECT_TYPE[SIZE];
    nowy->use = 0;
    nowy->next = NULL;
    return nowy;
}
void DeleteNode(NODE_STRUCT* obiekt) {
    if ( obiekt == NULL)return;
    if ( obiekt->object != NULL) delete[] obiekt->object;
    delete obiekt;
}
void Clear (NODE_STRUCT** obiekt) {
    if ( obiekt == NULL || *obiekt == NULL)return;
    while (*obiekt != NULL) {
        NODE_STRUCT* usun = (*obiekt)->next;
        DeleteNode(*obiekt);
        *obiekt = usun;
    }
}
void RemoveCurrent(NODE_STRUCT **lista, NODE_STRUCT *obiekt, BYTE indeks);
void AddFirst(NODE_STRUCT** lista,OBJECT_TYPE* obiekt) {
    if (obiekt == NULL || lista == NULL )return;
    if ( *lista == NULL) {
        NODE_STRUCT*nowy = NewNode();
        *(nowy->object) = *(obiekt);
        nowy->use = 1;
        *lista = nowy;
        return;
    }
    NODE_STRUCT* head = *lista;
    if ( head ->use == SIZE) {
        NODE_STRUCT* nowy = NewNode();
        *(nowy->object) = *(obiekt);
        nowy->next = head;
        nowy->use = 1;
        *lista = nowy;
        return;
    }
    for ( int i = head->use; i > 0; i--) {
        *(head->object + i) = *(head->object + i - 1);
    }
    *(head->object) = *obiekt;
    head->use++;
}
 void AddLast (NODE_STRUCT**lista,OBJECT_TYPE* obiekt){
    if (lista == NULL || obiekt == NULL){return;}
    if (*lista == NULL) {
        NODE_STRUCT*nowy = NewNode();
        nowy->next = NULL;
        *(nowy->object) = *(obiekt);
        nowy->use = 1;
        *lista = nowy;
        return;
    }
    NODE_STRUCT* head = (*lista);
        while (head->next != NULL) {
            head = (head->next);
        }
        if ( head->use >= SIZE) {
            NODE_STRUCT* dodany = NewNode();
            head->next = dodany;
            *(dodany->object) = *obiekt;
            dodany->use = 1;
            return;
        }
    *(head->object+(head->use)) = *obiekt;
    head->use++;
}
void GetFirst(NODE_STRUCT* lista, NODE_STRUCT** szukany, BYTE *indeks) {
    if (lista == NULL || lista->use == 0) {
       *szukany = NULL;
        return;
    }
    *szukany = lista;
    if (indeks != NULL)*indeks = 0;
    return;
}
void GetPrev(NODE_STRUCT*lista, NODE_STRUCT* wezel,BYTE wezelid,NODE_STRUCT**szukany, BYTE *indeks) {
    if ( lista == wezel && wezelid==0) {
        *szukany = NULL;
        return;
    }
    NODE_STRUCT* head = lista;
    NODE_STRUCT* prev = NULL;
    while (head!=NULL && head != wezel) {
        prev = head;
        head = head->next;
    }
    if (head == NULL)return;
    if ( wezelid < 0 )return;
    if (wezelid==0) {

        if (prev != NULL) {
            *szukany = prev;
            *indeks = prev->use-1;
        }
        else { *szukany = NULL;}
        return;
    }
    *szukany = head;
    *indeks = wezelid-1;
    return;
}
void RemoveFirst(NODE_STRUCT **lista) {
    if (lista==NULL || *lista ==NULL)return;
    NODE_STRUCT* head = *lista;
    if (head->use == 1) {
        if (head->next != NULL) {
            NODE_STRUCT* new_root = head->next;
            DeleteNode(head);
            *lista = new_root;
            return;
        }
        else {
            DeleteNode(head);
            *lista = NULL;
            return;
        }
    }
    OBJECT_TYPE* indeks  = head->object;
    for ( int i = 0;i<head->use-1;i++) {
        *(indeks) = *(indeks+1);
        indeks++;
    }
    head->use--;
    return;
}
void RemoveLast(NODE_STRUCT**lista) {
    if (lista==NULL || *lista ==NULL)return;
    NODE_STRUCT* head = *lista;
    NODE_STRUCT* prev = NULL;
    while (head->next != NULL) {
        prev=head;
        head = (head->next);
    }
    if ( head->use == 1) {
        DeleteNode(head);
        if ( prev == NULL) {
            *lista = NULL;
        }
        else prev->next = NULL;
        return;
    }
    head->use--;
}
void GetNext(NODE_STRUCT*lista,NODE_STRUCT*wezel,BYTE wezel_id,NODE_STRUCT**szukany,BYTE*indeks) {
    if ( lista == NULL)return;
    NODE_STRUCT* head = lista;
    while (head!=NULL && head != wezel) {
        head = head->next;
    }
    if (head == NULL)return;
    if (wezel_id >= head->use)return;
    if ( wezel_id == head->use-1) {
        *szukany = head->next;
        if ( head->next != NULL) {
            *indeks = 0;
        }
        return;
    }
    *szukany = head;
    *indeks = wezel_id+1;
}
void GetLast(NODE_STRUCT*lista,NODE_STRUCT**szukany,BYTE*indeks) {
    if ( lista == NULL) {
        *szukany = NULL;
        return;
    }
    NODE_STRUCT *ptr = lista;
    BYTE LAST;
    NODE_STRUCT* ostatni = ptr;
    while (ptr->next !=NULL) {
        ptr=ptr->next;
    }

    *szukany = ptr;
    *indeks = ptr->use-1;
}
void RemoveCurrent(NODE_STRUCT **lista, NODE_STRUCT *obiekt, BYTE indeks) {
    if (*lista == NULL || obiekt == NULL) return;
    NODE_STRUCT *head = (*lista);
    NODE_STRUCT *prev = NULL;
    while (head!=NULL && head != obiekt) {
        prev = head;
        head = head->next;
    }
    if (head==NULL)return;
    if (indeks >= obiekt->use || indeks < 0 )return;
    for (int i = indeks; i < head->use - 1; i++) {
        *(head->object + i) = *(head->object + i + 1);
    }
    head->use--;
    if (head->use == 0) {
        if (prev != NULL)
            prev->next = head->next;
        else *lista = head->next;
        DeleteNode(head);
    }
    return;
}
void Find(NODE_STRUCT*lista,OBJECT_TYPE*szukana,NODE_STRUCT** wezel,BYTE* indeks) {
    if (lista == NULL) {
        *wezel = NULL;
        return;
    }
    *wezel = lista;
    for ( int i = 0;i<lista->use;i++) {
        if ( *szukana == *(i + lista->object) ) {
            *indeks = i;
            return;
        }
    }
    Find(lista->next,szukana,wezel,indeks);
}
void RemovePrev(NODE_STRUCT** lista,NODE_STRUCT*szukany,BYTE indeks) {
    if (lista == NULL || * lista == NULL  || szukany == NULL || szukany->use <= indeks) {
        return ;
    }
    NODE_STRUCT* head = *lista;
    NODE_STRUCT* prev = NULL;
    NODE_STRUCT* prevbprev = NULL;
    while (head!=NULL && head!= szukany) {
        prevbprev = prev;
        prev = head;
        head = head->next;
    }
    if (head == NULL)return;
    if ( indeks == 0) {
        if ( prev == NULL)return;
        if ( prev->use == 1 && prevbprev==NULL) {
            DeleteNode(prev);
            *lista = head;
        }
        else if ( prev->use == 1 && prevbprev!=NULL) {
            prevbprev->next = head;
            DeleteNode(prev);
        }
        else prev->use--;
        return;
    }
    for ( int i = indeks-1;i<head->use-1;i++) {
        *(head->object+i)=*(head->object+i+1);
    }
    head->use--;
    return;
}
void RemoveNext(NODE_STRUCT* lista, NODE_STRUCT*szukany,BYTE indeks) {
    if ( lista == NULL)return;
    NODE_STRUCT* head = lista;
    while (head!=NULL && head!= szukany) {
        head = head->next;
    }
    if (head == NULL)return;
    if (indeks >= head->use)return;
    if ( indeks ==head->use-1) {
        RemoveFirst(&head->next);
        return;
    }
    for ( int i = indeks+1;i<head->use-1;i++) {
        *(head->object+i)=*(head->object+i+1);
    }
    head->use--;
    return;
}
void Czysc(NODE_STRUCT* gdziewrzucam,int naindeks,NODE_STRUCT* wezel,int miejsce ) {
    if ( wezel == NULL)return;
    if ( miejsce > 0) {
        int i = 0;
        while (wezel->use>0 && miejsce > 0) {
            *(gdziewrzucam->object+naindeks+i) = *(wezel->object+i);
            i++;
            miejsce--;
            gdziewrzucam->use++;
            wezel->use--;
        }
        if ( wezel->use ==0 ) {
            gdziewrzucam->next = wezel->next;
            DeleteNode(wezel);
            return;
        }
        for ( int j = 0;j<wezel->use;j++) {
            *(wezel->object+j) = *(wezel->object+i+j);
        }
    }
}
void Compress(NODE_STRUCT*lista) {
    if (lista==NULL) {
        return;
    }
    while (lista->next!=NULL) {
        if (lista->use == SIZE) {
            lista=lista->next;
        }
        else {
            //cout<<lista<<" "<<lista->use+0<<" "<<lista->next<<" "<<SIZE-lista->use+0<<endl;
            Czysc(lista,lista->use,lista->next,SIZE-lista->use);
        }
    }
}
int zlicz(NODE_STRUCT * lista) {
    if ( lista == NULL)return 0;
    else return lista->use + zlicz(lista->next);
}
void Reverse(NODE_STRUCT *lista) {
    if (lista == NULL) return;
    NODE_STRUCT *head = lista;
    NODE_STRUCT *nowalista =NULL;
    while (head != NULL) {
        for (int i = 0; i < head->use; i++) {
            AddFirst(&nowalista, head->object + i);
        }
        head = head->next;
    }
    Compress(nowalista);
    NODE_STRUCT *currentOld = lista;
    NODE_STRUCT *currentNew = nowalista;
    while (currentOld != NULL && currentNew != NULL) {
        currentOld->use = currentNew->use;
        for (int i = 0; i < currentNew->use; i++) {
            *(currentOld->object+i) = *(currentNew->object+i);
        }
        if (currentOld->next != NULL && currentNew->next == NULL) {
            Clear(&currentOld->next);
            currentOld->next = NULL;
        }
        currentOld = currentOld->next;
        currentNew = currentNew->next;
    }
    Clear(&nowalista);;
}
int isSpace(NODE_STRUCT *node) {
    if (node->next == NULL) {
        return 0;
    }
    if ( node->next->use < SIZE)return 1;
    return 0;
}
void wcisnij(NODE_STRUCT* wezel,OBJECT_TYPE obiekt) {
    OBJECT_TYPE toadd = obiekt;
    if ( wezel->use == SIZE) {
        wezel->use--;
        obiekt = *(wezel->object+wezel->use);
        AddFirst(&wezel,&toadd);
        wcisnij(wezel->next,obiekt);
    }
    else {
        AddFirst(&wezel,&toadd);
        return;
    }
}
void InsertNext(NODE_STRUCT* lista,NODE_STRUCT* wezel,BYTE indeks,OBJECT_TYPE* obiekt) {
    if ( lista == NULL || wezel == NULL || obiekt == NULL || indeks >=wezel->use)return;
    while (lista != wezel && lista!= NULL) {
        lista = lista->next;
    }
    NODE_STRUCT* root = wezel;
    if ( lista == NULL ) return;
    OBJECT_TYPE toadd = *(lista->object+(lista->use-1));//0
    if ( lista->use == SIZE) {
        if ( indeks+1 == wezel->use) {
            AddFirst(&wezel->next,obiekt);
            return;
        }
        for ( int i = lista->use-1;i>=indeks+1;i--) {
            *(lista->object+i) = *(lista->object+i-1);
        }
        *(lista->object+indeks+1) = *obiekt;
        int a = isSpace(root);
        if ( a == 0) {
            NODE_STRUCT*nowy = NewNode();
            nowy->next = root->next;
            root->next = nowy;
            *nowy->object = toadd;
            nowy->use++;
            return;
        }
        else {
            wcisnij(root->next,toadd);
        }
    }
    else {
        lista->use++;
        for ( int i = lista->use-1;i>=indeks+1;i--) {
            *(lista->object+i) = *(lista->object+i-1);
        }
        *(lista->object+indeks+1) = *obiekt;
    }
}
void InsertPrev(NODE_STRUCT** lista,NODE_STRUCT* wezel,BYTE indeks,OBJECT_TYPE* obiekt) {
    if (lista == NULL || *lista == NULL || wezel == NULL || obiekt == NULL || indeks >=wezel->use)return;
    NODE_STRUCT* head = *lista;
    NODE_STRUCT* prev = NULL;
    while (head!= wezel && head!= NULL) {
        prev = head;
        head = head->next;
    }
    if ( head == NULL)return;
    OBJECT_TYPE toadd = *(head->object);
    if ( head->use < SIZE) {
        head->use++;
        for ( int i = head->use-1;i>indeks;i--) {
            *(head->object+i) = *(head->object+i-1);
        }
        *(head->object+indeks) = *obiekt;
        return;
    }
        if (prev == NULL ) {
            if ( indeks == 0) {
                AddFirst(lista,obiekt);
                return;
            }
            if ( indeks == 1) {
                AddFirst(lista,&toadd);
                *head->object = *obiekt;
                return;
            }
                AddFirst(lista,&toadd);
            for ( int i = 0;i<indeks;i++) {
                *(head->object+i) = *(head->object+i+1);
            }
            *(head->object+indeks-1) = *obiekt;
                return;
        }
            if ( prev->use >=SIZE) {
                NODE_STRUCT* nowy = NewNode();
                nowy->use = 0;
                nowy->next = head;
                prev->next = nowy;
                if ( indeks == 0) {
                    AddFirst(&nowy,obiekt);
                    return;
                }
                AddFirst(&nowy,&toadd);
                if ( indeks == 1) {
                    *(head->object) = *obiekt;
                    return;
                }
                else {
                    for ( int i = 0;i<indeks;i++) {
                        *(head->object+i) = *(head->object+i+1);
                    }
                    *(head->object+indeks-1) = *obiekt;
                    return;
                }
            }
    NODE_STRUCT* kopia = head;
    if ( indeks == 0 ) {
        prev->next =NULL;
        AddLast(&prev,obiekt);
        prev->next = head;
        return;
    }
    prev->next =NULL;
        AddLast(&prev,head->object);
        *head->object = *obiekt;
        prev->next = head;
    if ( indeks == 1) {
        return;
    }
    for ( int i = 0;i<indeks;i++) {
        *(head->object+i) = *(head->object+i+1);
    }
    *(head->object+indeks-1) = *obiekt;
}