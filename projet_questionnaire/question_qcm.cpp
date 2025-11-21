#include "question_qcm.h"
#include <cstdlib>

QuestionQCM::QuestionQCM(const std::string& intitule,
    const std::string& texte,
    const std::array<std::string, 4>& propositions,
    int bonneReponse)
    : Question(intitule, texte),
    d_propositions(propositions),
    d_bonneReponse(bonneReponse)
{
}

bool QuestionQCM::estBonneReponse(const std::string& rep) const {
    try {
        int valeur = std::stoi(rep);
        return valeur == d_bonneReponse;
    }
    catch (...) {
        return false;
    }
}

void QuestionQCM::afficherBonneReponse(std::ostream& os) const {
    os << d_bonneReponse << " : " << d_propositions[d_bonneReponse - 1];
}
