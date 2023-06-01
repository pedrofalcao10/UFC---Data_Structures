class DequeVetor
  {
   ... (atributos/campos da classe) ...

   public:

   double consultar_dir () { ... }
   double consultar_esq () { ... }

   DequeVetor() { ... }

   ~DequeVetor () { ... }

   void inserir_dir (double e) { ... }
   void inserir_esq (double e) { ... }

   void remover_dir () { ... }
   void remover_esq () { ... }

   bool vazio () { ... }
  };

  #include <iostream>
using std::cout;

const char* vazio_str (DequeVetor &D)
  {
   if (D.vazio()) return "Sim";
   else           return "Não";
  }

int main ()
  {
   DequeVetor D;

   D.inserir_dir(1);  D.inserir_dir(2);  D.inserir_dir(3);

   cout << "RE: " << D.consultar_esq() << '\n';  D.remover_esq();
   cout << "RE: " << D.consultar_esq() << '\n';  D.remover_esq();

   D.inserir_esq(4);  D.inserir_esq(5);

   cout << "RD: " << D.consultar_dir() << '\n';  D.remover_dir();
   cout << "RD: " << D.consultar_dir() << '\n';  D.remover_dir();

   cout << "Vazio? -> " << vazio_str (D) << '\n';

   cout << "RD: " << D.consultar_dir() << '\n';  D.remover_dir();

   cout << "Vazio? -> " << vazio_str (D) << '\n';

   D.inserir_esq(6);  D.inserir_esq(7);  D.inserir_dir(8);

   cout << "RD: " << D.consultar_dir() << '\n';  D.remover_dir();
   cout << "RD: " << D.consultar_dir() << '\n';  D.remover_dir();
   cout << "RD: " << D.consultar_dir() << '\n';  D.remover_dir();
  }