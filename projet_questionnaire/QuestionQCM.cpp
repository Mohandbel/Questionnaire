#include "QuestionQCM.h"
#include <cstdlib>
#include<vector>
#include<iostream>

QuestionQCM::QuestionQCM(const std::string& intitule,
    const std::string& texte,
    const std::vector<std::string>& propositions,
    int bonneReponse)
    : Question(intitule, texte),
    d_propositions(propositions),
    d_bonneReponse(bonneReponse)
{
}

bool QuestionQCM::verifierReponse( std::string rep) const {
    try {
        int valeur = std::stoi(rep);
        return valeur == d_bonneReponse;
    }
    catch (...) {
        return false;
    }
}

void QuestionQCM::AfficherQuestion() const {
    Question::AfficherQuestion();
    for (size_t i = 0; i < d_propositions.size(); ++i) {
        std::cout << (i + 1) << ". " << d_propositions[i] << std::endl;
    }
}
void QuestionQCM::AfficherReponse() const
{
    std::cout << "La reponse est" << d_propositions[d_bonneReponse] << std::endl;
}