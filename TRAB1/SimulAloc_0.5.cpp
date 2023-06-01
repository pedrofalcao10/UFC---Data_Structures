#include <iostream>

struct SimulAloc{
    struct Noh{int ini, tam; Noh *prox;};

    Noh *prim = nullptr;

    bool inicializar(int ini, int tam)
    {
        if(prim != nullptr) return 1;

        prim = new Noh{ini, tam, nullptr};

        if(!prim) return 1;

        return 0;
    }

    int alocar(int tam)
    {
        if(prim == nullptr) return -1;

        int pos = -1;
        Noh *aux1;

        if(prim->tam >= tam){
            pos = prim->ini + prim->tam - tam;
            prim->tam -= tam;

            if(prim->tam == 0){
                aux1 = prim;
                prim = prim->prox;

                delete aux1;
            }
            return pos;
        }

        for(Noh *aux2 = prim; aux2->prox != nullptr; aux2 = aux2->prox){
            if(aux2->prox->tam >= tam){
                pos = aux2->prox->ini + aux2->prox->tam - tam;
                aux2->prox->tam -= tam;

                if(aux2->prox->tam == 0){
                    aux1 = aux2->prox;
                    aux2->prox = aux1->prox;

                    delete aux1;
                }
                return pos;
            }
        }
        return pos;
    }

    bool desalocar(int ini, int tam)
    {
        if(prim == nullptr){
            prim = new Noh{ini, tam, nullptr};

            return 0;
        }

        Noh *aux1, *aux2;

        if(ini + tam < prim->ini){
            aux1 = new Noh{ini, tam, prim};

            prim = aux1;

            return 0;
        }
        if(ini + tam == prim->ini){
            prim->ini = ini;
            prim->tam += tam;

            return 0;
        }

        for(aux2 = prim; aux2->prox != nullptr; aux2 = aux2->prox){
            if(aux2->ini + aux2->tam == ini && ini + tam == aux2->prox->ini){
                aux1 = aux2->prox;

                aux2->tam += tam + aux1->tam;
                aux2->prox = aux1->prox;

                delete aux1;

                return 0;
            }
            if(aux2->ini + aux2->tam == ini && ini + tam < aux2->prox->ini){
                aux2->tam += tam;

                return 0;
            }
            if(aux2->ini + aux2->tam < ini && ini + tam == aux2->prox->ini){
                aux2->prox->ini = ini;
                aux2->prox->tam += tam;

                return 0;
            }
            if(aux2->ini + aux2->tam < ini && ini + tam < aux2->prox->ini){
                aux1 = new Noh{ini, tam, aux2->prox};

                aux2->prox = aux1;

                return 0;
            }
        }

        if(aux2->ini + aux2->tam == ini){
            aux2->tam += tam;

            return 0;
        }
        if(aux2->ini + aux2->tam < ini){
            aux2->prox = new Noh{ini, tam, nullptr};

            return 0;
        }
        return 1;
    }

    void terminar()
    {
        Noh *aux1;

        while(prim != nullptr){
            aux1 = prim;
            prim = prim->prox;

            delete aux1;
        }
    }
};