#include "QuestionNumerique.h"
#include <cstdlib> 
#include <stdexcept>
#include<iostream>

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

bool QuestionNumerique::verifierReponse(std::string reponseUtilisateur) const {
    try {
        int valeur = std::stoi(reponseUtilisateur);

        if (valeur < d_min || valeur > d_max)
            return false;

        return valeur == d_bonneReponse;
    }
    catch (...) {
        return false;
    }
}

void QuestionNumerique::AfficherQuestion() const {
    Question::AfficherQuestion();
    std::cout << "(Réponse attendue entre " << d_min
        << " et " << d_max << ")" << std::endl;
}
int QuestionNumerique::max()const
{
    return d_max;
}
int QuestionNumerique::min() const
{
    return d_min;
}
