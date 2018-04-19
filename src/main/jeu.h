#ifndef JEU_H
#define JEU_H

#include <time.h>
#include <ctime>
#include "./Sort.h"
#include "./push_swap.h"
using namespace std;

class jeu
{
    public:
        /** Default constructor */
        jeu();
        /** Default destructor */
        virtual ~jeu();

        /** Access Chronometre
         * \return The current value of m_Chronometre
         */
        double GetChronometre() { return chronometre; }
        /** Set Chronometre
         * \param val New value to set
         */
        void SetChronometre(double val) { chronometre = val; }
        /** Access m_niveau[i]
         * \return The current value of niveau[i]
         */
        niveau &Getniveau(int j) { return niveaux[j]; }
        /** Set niveau[10]
         * \param val New value to set
         */
        void Setniveau(niveau val,int i) { niveaux[i] = val; }
        /** Access m_totalEtoile
         * \return The current value of m_totalEtoile
         */
        int GettotalEtoile() { return totalEtoile; }
        /** Set totalEtoile
         * \param val New value to set
         */
        void SetTotalEtoile(int val) {totalEtoile = val; }

        void InitJeu();

        void SaveJeu();

        double modifChrono(struct tm timer);

        void testRegression();

        int verifOrdre(TableauDynamique tab);

        void afficheErreur();

        void afficherAction(TableauDynamique tabA,TableauDynamique tabB,niveau niveau1);

        int test(TableauDynamique tabA,TableauDynamique tabB,int i,struct tm * ttime);

        void afficheHistoire(int i);

        bool jeuAction(TableauDynamique tabA, TableauDynamique tabB,niveau niveau1,int i,int & m);

        void setVp(int niveau,int nbCoup);

        int verifnbCoup(niveau niveau,int nbCoup);

	      void aleatoireGen(niveau & niveau1);

    protected:

    private:
        double chronometre;//!< Member variable "m_Chronometre"
        niveau niveau1;
        niveau niveau2;
        niveau niveaux[10];//!< Member variable "m_niveau[10]"
        int totalEtoile; //!< Member variable "m_totalEtoile"
};

#endif // JEU_H
