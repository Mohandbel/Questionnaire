#ifndef QUESTION_TEXTE_H
#define QUESTION_TEXTE_H

#include "Question.h"
#include<string>

class QuestionTexte : public Question {
public:
    QuestionTexte(const std::string& intitule,
         const std::string& texte,
         const std::string& bonneReponse);

     void afficher()const  override;
     bool verifierReponse(std::string reponseUtilisateur) const override;

private:
    std::string d_bonneReponse;
};

#endif