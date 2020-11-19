#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this = NULL;
	this = (LinkedList*)malloc(sizeof(LinkedList));
	if(this != NULL)    //chequeo que haya memoria reservada
	{
		this->size = 0;         //tengo que inicializar los valores de la lista para que no me tire basura
		this->pFirstNode = NULL;
	}
	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int returnAux = -1;

	if(this != NULL)
	{
		returnAux = this->size;
	}

	return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex) //funcion static, solo dentro de esta biblioteca
{
    int i;
    Node* pNode;
    pNode = NULL;
    if(this != NULL && nodeIndex>=0 && nodeIndex < ll_len(this)) //verifico que el indice sea menor al size del LL
    {
    	pNode = this->pFirstNode;
		for(i=0; i<nodeIndex; i++)		// si el index es 0 no entra y deja el pfirstNode, que es igual al primer nodo[0]. si pone 1 ya es el sdo nodo entonces queda nextnode
		{
			pNode = pNode->pNextNode;    //si entra lo va cargando y aumentando hasta dejar el del indice(que no entro pero lo evaluo desde el anterior)
		}
    }									// entonces te queda el pnode del indice.
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pPreviousNode;
    Node* pNewNode;

    pNewNode = (Node*) malloc(sizeof(Node));

    if((this != NULL) && (nodeIndex>=0) && (nodeIndex<=ll_len(this)) && (pNewNode !=NULL))//valido que la lista no sea nula, el <= es para cuando le queres agregar uno al final

    {
    	pNewNode->pElement = pElement; //asigno la direccion al dato

		if(nodeIndex == 0)  //si quiero agregar un nodo en la primer posicion
		{
			pNewNode->pNextNode = this->pFirstNode;//guardo en el nuevo nodo la direccion del previo primer nodo
			this->pFirstNode = pNewNode;//hago que la lista apunte al nuevo primer nodo. si la lista estaba vacia pnextnode queda NULL y first node queda con la original

		}
		/*else if (nodeIndex == ll_len(this)) //si quiero agregar nodo al final
		{
			pPreviousNode = getNode(this, nodeIndex-1);//obtengo el nodo anterior en la lista, -1 porque quiero traer el anterior
			pPreviousNode->pNextNode= pNewNode; //al nodo anterior le asigno el nuevo nodo
			pNewNode->pNextNode = NULL;  //dado que es el final de la lista, el nuevo nodo apunta a NULL
		}*/
		else	//en el medio o final
		{
			pPreviousNode = getNode(this, nodeIndex-1);
			pNewNode->pNextNode = pPreviousNode->pNextNode;//al nuevo nodo le asigno el nodo al que apuntaba el anterior, y si es el ultimo, queda null xq el anterior era null
			pPreviousNode->pNextNode = pNewNode;//al nodo anterior le asigno el nuevo nodo
		}

		this->size++;
		returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = addNode(this, ll_len(this), pElement);
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode;

    if(this!=NULL && index>=0 && index<=ll_len(this))
    {
        pNode = getNode(this,index);
        if(pNode!=NULL)
        {
            returnAux=pNode->pElement;
        }
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pAuxNode;

    if(this!= NULL && index>=0 && index<ll_len(this))
    {
        pAuxNode=getNode(this,index);
        if(pAuxNode!=NULL)
        {
            pAuxNode->pElement=pElement;
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNodeToRemove;
    Node* prevNode;

    if(this!= NULL && index>=0 && index<this->size){
        if(index==0){
        	pNodeToRemove = getNode(this,index);
            this->pFirstNode=pNodeToRemove->pNextNode; //para que el pfirst node no apunte al que queria borrar sino al siguiente
        }else{
        	pNodeToRemove=getNode(this,index);
        	prevNode=getNode(this,index-1);
        	prevNode->pNextNode=pNodeToRemove->pNextNode; //para que el pNext node del anterior no apunte al que queria borrar sino al siguiente
        }
        this->size--;
        returnAux=0;
        free(pNodeToRemove);  // lo libero de memoria
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)         // elimino elementos
{
    int returnAux = -1;

    if(this!=NULL){
       for(int i=0;i<ll_len(this);i++)
       {
            ll_remove(this,i);
        }
        if(ll_len(this)==0)
        {
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        ll_clear(this);
        free(this);
        this = NULL;

        returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pAuxNode;
    if(this!=NULL)
    {
        for(int i=0; i<ll_len(this);i++)
        {
            pAuxNode=getNode(this,i);
            if(pAuxNode!=NULL)
            {
                if(pAuxNode->pElement==pElement)
                {
                returnAux=i;
                }
            }

        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if(ll_len(this)==0)
        {
            returnAux=1;
        }else
        {
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL && index>=0 && index<=ll_len(this))
    {
        returnAux=addNode(this,index,pElement);
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this!=NULL && index>=0 && index<=ll_len(this))
    {
        returnAux=ll_get(this,index);
        ll_remove(this,index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* pNodeAux;
    if(this != NULL)
    {
        pNodeAux = NULL;
        returnAux = 0;
        for(i=0; i<ll_len(this); i++)
        {
            pNodeAux = ll_get(this, i);
            if(pNodeAux == pElement)
            {
                returnAux = 1;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    int validate = -1;
    Node* pNodeAux;
    if(this != NULL && this2 != NULL)
    {
        returnAux = 1;
        pNodeAux = NULL;
        for(i=0; i<ll_len(this2); i++)
        {
            pNodeAux = ll_get(this2, i);
            validate = ll_contains(this, pNodeAux);
            if(validate != 1)
            {
                returnAux = 0;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pAux=NULL;

    if(this!=NULL && from >=0 && from<to && to<=ll_len(this))
    {
        cloneArray=ll_newLinkedList();
        if(cloneArray!=NULL)
        {
            for(int i=from;i<to;i++)
            {
                pAux=ll_get(this,i);
                if(pAux!=NULL)
                {
                    addNode(cloneArray,i,pAux); // voy copiando a la nueva lista cada nodo (desde hasta) con su indice.
                }

            }
        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL)
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {
            cloneArray = ll_subList(this, 0, ll_len(this));
        }
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)   //pfunc recibe valores y aplica
{
    int returnAux = -1;
    int order_validate;
    int i;
    int j;
    void* pElementOne;
    void* pElementTwo;
    void* pAuxElement;


    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
        for(i=0; i<ll_len(this)-1; i++)
        {
            pElementOne = ll_get(this, i);
            for(j=i+1; j<ll_len(this); j++)
            {
                pElementTwo = ll_get(this, j);
                order_validate = pFunc(pElementOne, pElementTwo);

                if((order==1 && (order_validate==1)) ||
                   (order==0 && (order_validate==-1)))
                {
					pAuxElement = pElementOne;
					pElementOne = pElementTwo;
					pElementTwo = pAuxElement;

                }
                ll_set(this, i, pElementOne);
                ll_set(this, j, pElementTwo);
            }
        }
        returnAux = 0;
    }
    return returnAux;

}

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* pListAux = NULL;
    void* pElement = NULL;
    int len=ll_len(this);

    if(this != NULL &&len>0)
    {
    	pListAux = ll_newLinkedList();
        if(pListAux != NULL)
        {
            for(int i=0;i<len;i++)
            {
            	pElement=ll_get(this, i);
                if(pElement!=NULL)
                {
                    if(pFunc(pElement)==0)
                    {
                        ll_add(pListAux,pElement);
                    }
                }

            }
        }
    }
    return pListAux;
}

//funcion que recorre el arraylist y que haga la funcion, ej imprimir,  incrementar salario 10%.  reduce

int ll_map(LinkedList* this, int (*pFunc)(void*))
{
	int retorno= -1;
    void* pAuxElement = NULL;
    int len=ll_len(this);

    if(this!=NULL &&len>0)
    {
            for(int i=0;i<len;i++)
            {
                pAuxElement=ll_get(this, i);
                if(pAuxElement!=NULL)
                {
                    if(pFunc(pAuxElement)==0)
                    {
                    retorno=0;
                    }
                }

            }
    }
    return retorno;
}

// reduce una lista a un numero, podemos tener reducefloat y reduceInt. devuelven un valor y lo acumulan quiero obtener suma salario empleados, promedio edad empleados

int ll_reduceInt(LinkedList* this, int (*pFunc)(void*))
{
    void* pAuxElement = NULL;
    int acumulado=0;
    int len=ll_len(this);

    if(this!=NULL &&len>0)
    {
            for(int i=0;i<len;i++)
            {
                pAuxElement=ll_get(this, i);
                if(pAuxElement!=NULL)
                {
                    acumulado = acumulado +pFunc(pAuxElement);
                }

            }
    }
    return acumulado;
}
float ll_reduceFloat(LinkedList* this, float (*pFunc)(void*))
{
    void* pAuxElement = NULL;
    float acumulado=0;
    int len=ll_len(this);

    if(this!=NULL &&len>0)
    {
            for(int i=0;i<len;i++)
            {
                pAuxElement=ll_get(this, i);
                if(pAuxElement!=NULL)
                {
                    acumulado = acumulado +pFunc(pAuxElement);
                }

            }
    }
    return acumulado;
}




