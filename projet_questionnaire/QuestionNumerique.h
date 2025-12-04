#ifndef QUESTIONNUMERIQUE_H
#define QUESTIONNUMERIQUE_H
#include"Question.h"
class QuestionNumerique :public Question
{
public:
    QuestionNumerique(const std::string& intitule,
        const std::string& texte,
        int bonneReponse,
        int min,
        int max);
    int max() const;
    int min()const;

    bool verifierReponse(std::string reponseUtilisateur) const override;
    void afficher() const override;

private:
    int d_bonneReponse;
    int d_min;
    int d_max;
};
#endif //QUESTIONNUMERIQUE_H
