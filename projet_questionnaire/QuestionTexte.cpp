#include "QuestionTexte.h"
#include<string>
#include<iostream>

QuestionTexte::QuestionTexte(const std::string& intitule,
    const std::string& texte,
    const std::string& bonneReponse)
    : Question(intitule, texte),
    d_bonneReponse(bonneReponse)
{
}

bool QuestionTexte::verifierReponse(std::string reponseUtilisateur) const {
    return reponseUtilisateur == d_bonneReponse;
}

void QuestionTexte::afficher() const{
    std::cout << "Intitulé : " << d_intitule << std::endl;
    std::cout << "Question : " << d_texte << std::endl;
    std::cout << "Reponse : " << d_bonneReponse << std::endl;
}
