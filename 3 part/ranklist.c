#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 13
#define DBG 0

FILE * f, *f1;

typedef struct SkipList{
    int key;
    char val[10];
    int cnt[M];
    struct SkipList *next[M];
} SkipList;


void InitipList(SkipList * l) {
    int i;
    for(i=0; i<M; i++){
        l->next[i] = NULL;
        l->cnt[i] = 0;
    }
}

int MapEmpty(SkipList *l) {
    return l->next[0] == NULL;
}

SkipList *Succ(SkipList *x) {
    return x->next[0];
}

int Skip(SkipList *l, int key, SkipList **p, int * mr) {
    int r = 0;
    SkipList *x = l;
    int i = M - 1;
    while (i >= 0) {
        while (x->next[i] != NULL && x->next[i]->key < key) {
            r += x->cnt[i];
            x = x->next[i];
        }
        if(mr!=NULL)mr[i] = r-1;
        p[i] = x;
        i--;
    }
    return r;
}

int Rank(SkipList *l, int key) {
    SkipList **p = calloc(M, sizeof(SkipList*));
    int r = Skip(l, key, p, NULL);
    free(p);
    return r;
}
/*
int MapSearch(SkipList *l, int key) {
    SkipList **p = calloc(M, sizeof(SkipList*));
    Skip(l, key, p, NULL);
    int x = *Succ(p[0]);
    free(p);
    return (x->next != NULL && x->key == key);
}
*/
char * Lookup(SkipList *l, int key) {
    SkipList **p = calloc(M, sizeof(SkipList*));
    Skip(l, key, p, NULL);
    SkipList * x = Succ(p[0]);
    free(p);
    return x->val;
}
int ii=1;
void Insert(SkipList *l, int key, char * str) {
    SkipList **p = calloc(M, sizeof(SkipList*));
    int * mr = calloc(M, sizeof(int));
    Skip(l, key, p, mr);

    SkipList *x = calloc(1, sizeof(SkipList));
    x->key = key;
    strcpy(x->val, str);
    x->cnt[0] = 1;
    int i;
    for(i=0; i<1; i++){
        int d = p[i]->cnt[i];
        x->cnt[i] = 1;
        p[i]->cnt[i] = 1;
        x->next[i] = p[i]->next[i];
        p[i]->next[i] = x;
    }
    int r = rand();
if(DBG){
/*
if(ii==1)r = 30695;
if(ii==2)r = 13876;
if(ii==3)r = 15006;
if(ii==4)r = 14815;
if(ii==5)r = 30539;
if(ii==6)r = 11117;
ii++;

fprintf(f1, "r = %d\n", r);
*/
}
    for(; i<M && r % 2; i++, r/=2){
        int d = p[i]->cnt[i];
        x->cnt[i] = d ? d - (mr[0] - mr[i]) : 0;
        p[i]->cnt[i] = mr[0] - mr[i] + 1;
        x->next[i] = p[i]->next[i];
        p[i]->next[i] = x;
    }
    for(; i<M && p[i]->cnt[i]; i++){
        p[i]->cnt[i]++;
    }
    free(p);
    free(mr);
}

void DeleteFirst_(SkipList *l) {
    SkipList * x = l->next[0];
    int i;
    for(i=0; i<M && l->next[i]; i++){
        l->next[i] = x->next[i];
    }
    free(x);
}
void Destroy(SkipList *l) {
    while(!MapEmpty(l))
        DeleteFirst_(l);
}
void Delete(SkipList *l, int key) {
    SkipList **p = calloc(M, sizeof(SkipList*));
    Skip(l, key, p, NULL);
    SkipList * x = Succ(p[0]);
    int i;
    for(i=0; i<M; i++){
        if(p[i]->next[i] == x){
            p[i]->next[i] = x->next[i];
            p[i]->cnt[i] += x->cnt[i] - 1;
        }else if(p[i]->cnt[i]){
            p[i]->cnt[i]--;
        }
    }
    free(p);
    free(x);
}

int main() {
    srand(time(0));
    SkipList L;
    SkipList *l = &L;
    InitipList(l);

    int n, i, key;
    char str[10];
    char *s = str;
if(DBG){
f = fopen("text.txt", "rt");
f1 = fopen("text1.txt", "wt");
fscanf(f, "%d", &n);
}else
    scanf("%d", &n);
    for (i=0; i < n; i++) {
if(DBG){
fscanf(f, "%s", s);
printf("\n%d %s\n", i, s);
}else
        scanf("%s", s);
        if (s[0] == 'I'){
if(DBG){
fscanf(f, "%d%s", &key, s);
}else
            scanf("%d%s", &key, s);
            Insert(l, key, s);
        }
        else if (s[0] == 'L') {
if(DBG){
fscanf(f, "%d",&key);
}else
            scanf("%d", &key);
            char * val = Lookup(l, key);
if(DBG){
fprintf(f1, "%s\n", val);
}else
            printf("%s\n", val);
        }
        else if (s[0] == 'D') {
if(DBG){
fscanf(f, "%d",&key);
}else
            scanf("%d",&key);
            Delete(l, key);
        }
        else if (s[0] == 'R') {
if(DBG){
fscanf(f, "%d",&key);
}else
            scanf("%d",&key);
            int r = Rank(l, key);
if(DBG){
fprintf(f1, "%d\n", r);
}else
            printf("%d\n", r);
        }
if(DBG){
//fprintf(f1, "%8d %8d(%3d) %8d(%3d) %8d(%3d)\n", l, l->next[0], l->cnt[0], l->next[1], l->cnt[1], l->next[2], l->cnt[2]);
SkipList * x = l;
while(x->next[0]){
x = x->next[0];
//fprintf(f1, "%8d %8d(%3d) %8d(%3d) %8d(%3d) %2d (%s)\n", x, x->next[0], x->cnt[0], x->next[1], x->cnt[1], x->next[2], x->cnt[2], x->key, x->val);
}
//fprintf(f1, "\n");
}    }
    Destroy(l);
}
