#ifndef QUESTION_TEXTE_H
#define QUESTION_TEXTE_H

#include "Question.h"
#include<string>

class QuestionTexte : public Question {
public:
    QuestionTexte(const std::string& intitule,
         const std::string& texte,
         const std::string& bonneReponse);

     void AfficherQuestion()const  override;
     bool verifierReponse(const std::string& reponseUtilisateur) const override;
     void AfficherReponse() const override;
     void ecrire(std::ostream& os)const override;

private:
    std::string d_bonneReponse;
};

#endif