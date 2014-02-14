#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

#define MAX 10

struct link
{

            int freq;

            char ch[MAX];

            struct link* right;

            struct link* left;

};

typedef struct link node;

void sort(node *[], int);

node* create(char[], int);

void sright(node *[], int);

void Assign_Code(node*, int [], int);

void Delete_Tree(node *);

int main()

{

            node* ptr, * head;

            int i, n, total = 0, u, c[15];

            char str[MAX];

            node* a[12];

            int freq;


            printf(  "Algoritmul lui Huffman\n");

            printf("\n Nr litere pt codificare:");/*input
the no. of letters*/

            scanf("%d", &n);

            for (i = 0; i < n; i++)

            {

                        printf("Litera&frecventa:");

                        scanf("%s %d", str, &freq);

                        a[i] = create(str, freq);

            }

            while (n > 1)

            {

                        sort(a, n);

                        u = a[0]->freq + a[1]->freq;

                        strcpy(str,a[0]->ch);

                        strcat(str,a[1]->ch);

                        ptr = create(str, u);

                        ptr->right = a[1];

                        ptr->left = a[0];

                        a[0] = ptr;

                        sright(a, n);

                        n--;

            }

            Assign_Code(a[0], c, 0);

            getch();

            Delete_Tree(a[0]);

}

node* create(char a[], int x)

{

            node* ptr;

            ptr = (node *) malloc(sizeof(node));

            ptr->freq = x;

            strcpy( ptr->ch , a);

            ptr->right = ptr->left = NULL;

            return(ptr);

}

void sort(node* a[], int n)

{

            int i, j;

            node* temp;

            for (i = 0; i < n - 1; i++)

                        for (j = i; j < n; j++)

                                    if (a[i]->freq > a[j]->freq)

                                    {

                                                temp = a[i];

                                                a[i] = a[j];

                                                a[j] = temp;

                                    }

}

void sright(node* a[], int n)

{

            int i;

            for (i = 1; i < n - 1; i++)

                        a[i] = a[i + 1];

}

void Assign_Code(node* tree, int c[], int n)

{

            int i;

            if ((tree->left == NULL) && (tree->right == NULL))

            {

                        printf("%s cod:", tree->ch);

                        for (i = 0; i < n; i++)

                         {

                          printf("%d", c[i]);

                         }

                        printf("\n");

            }

            else

            {

                        c[n] = 1;

                        n++;

                        Assign_Code(tree->left, c, n);

                        c[n - 1] = 0;

                        Assign_Code(tree->right, c, n);

            }

}

void Delete_Tree(node * root)

{

    if(root!=NULL)

    {

            Delete_Tree(root->left);

            Delete_Tree(root->right);

            free(root);

    }

}
