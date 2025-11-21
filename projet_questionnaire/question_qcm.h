#ifndef QUESTION_QCM_H
#define QUESTION_QCM_H

#include "question.h"
#include <array>

class QuestionQCM : public Question {
public:
    QuestionQCM(const std::string& intitule,
        const std::string& texte,
        const std::array<std::string, 4>& propositions,
        int bonneReponse);

    bool estBonneReponse(const std::string& rep) const override;
    void afficherBonneReponse(std::ostream& os) const override;

private:
    std::array<std::string, 4> d_propositions;
    int d_bonneReponse;
};

#endif

