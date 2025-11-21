#include "question_numerique.h"
#include <cstdlib> 
#include <stdexcept> 

QuestionNumerique::QuestionNumerique(const std::string& intitule,
    const std::string& texte,
    int bonneReponse,
    int min,
    int max)
    : Question(intitule, texte),
    d_bonneReponse(bonneReponse),
    d_min(min),
    d_max(max)
{
}

bool QuestionNumerique::estBonneReponse(const std::string& rep) const {
    try {
        int valeur = std::stoi(rep);

        if (valeur < d_min || valeur > d_max)
            return false;

        return valeur == d_bonneReponse;
    }
    catch (...) {
        return false; 
    }
}

void QuestionNumerique::afficherBonneReponse(std::ostream& os) const {
    os << d_bonneReponse;
}
