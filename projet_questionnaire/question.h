#pragma once
#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <iostream>

class Question {
public:
    // Constructeur
    Question(const std::string& intitule, const std::string& texte)
        : d_intitule(intitule), d_texte(texte) {
    }

    // Destructeur 
    virtual ~Question() = default;

    // getters
    std::string intitule() const { return d_intitule; }
    std::string texte() const { return d_texte; }

    // affichage de base de la question
    virtual void afficher(std::ostream& os) const {
        os << d_intitule << " : " << d_texte;
    }

    // Méthodes abstraites 
    virtual bool estBonneReponse(const std::string& reponseUtilisateur) const = 0;
    virtual void afficherBonneReponse(std::ostream& os) const = 0;

private:
    std::string d_intitule;  
    std::string d_texte;     
};

#endif
