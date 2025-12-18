#include "evaluation.h"


Evaluation::Evaluation(std::vector<std::unique_ptr<Question>> questions)
    : d_listeQuestions(std::move(questions)),
    d_indiceCourant(0),
    d_nbEssais(0),
    d_nbBonnesReponses(0)
{

}


bool Evaluation::aEncoreQuestions() const {

    return d_indiceCourant < static_cast<int>(d_listeQuestions.size());
}
/*
Question* Evaluation::questionCourante() const {
    if (!aEncoreQuestions()) return nullptr;
    return d_listeQuestions[d_indiceCourant].  ;// on vas utiliser la fonction de la classe question qui retourne une question
}
*/
Question* Evaluation::questionCourante() const {
    // Vérification de sécurité : s'il n'y a plus de questions
    if (!aEncoreQuestions()) {
        return nullptr;
    }

    // Extrait le pointeur brut du unique_ptr avec .get()
    return d_listeQuestions[d_indiceCourant].get();
}


void Evaluation::questionSuivante() {
    // Vérifie qu'il reste des questions avant d'incrémenter
    if (aEncoreQuestions()) {
        d_indiceCourant++;
    }
}


int Evaluation::nombreQuestions() const {

    return static_cast<int>(d_listeQuestions.size());
}


int Evaluation::nombreEssais() const {
    return d_nbEssais;
}


int Evaluation::nombreBonnesReponses() const {
    return d_nbBonnesReponses;
}
