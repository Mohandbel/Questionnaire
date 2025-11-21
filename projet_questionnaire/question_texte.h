#ifndef QUESTION_TEXTE_H
#define QUESTION_TEXTE_H

#include "question.h"

class QuestionTexte : public Question {
public:
    QuestionTexte(const std::string& intitule,
        const std::string& texte,
        const std::string& bonneReponse);

    bool estBonneReponse(const std::string& r) const override;
    void afficherBonneReponse(std::ostream& os) const override;

private:
    std::string d_bonneReponse;
};

#endif

