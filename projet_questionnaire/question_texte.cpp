#include "question_texte.h"

QuestionTexte::QuestionTexte(const std::string& intitule,
    const std::string& texte,
    const std::string& bonneReponse)
    : Question(intitule, texte),
    d_bonneReponse(bonneReponse)
{
}

bool QuestionTexte::estBonneReponse(const std::string& r) const {
    return r == d_bonneReponse;
}

void QuestionTexte::afficherBonneReponse(std::ostream& os) const {
    os << d_bonneReponse;
}
