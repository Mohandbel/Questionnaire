#ifndef QUESTION_NUMERIQUE_H
#define QUESTION_NUMERIQUE_H

#include "question.h"

class QuestionNumerique : public Question {
public:
    QuestionNumerique(const std::string& intitule,
        const std::string& texte,
        int bonneReponse,
        int min,
        int max);

    bool estBonneReponse(const std::string& rep) const override;
    void afficherBonneReponse(std::ostream& os) const override;

private:
    int d_bonneReponse;
    int d_min;
    int d_max;
};

#endif

