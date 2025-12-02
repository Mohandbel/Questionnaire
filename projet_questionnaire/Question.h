#ifndef QUESTION_H
#define QUESTION_H
#include<string>
class Question
{
public:
	Question(std::string intitule, std::string texte);
	virtual ~Question() = default;
	std::string getIntitule()const;
	std::string getTexte()const;
	virtual void afficher()const = 0;
	virtual bool verifierReponse(std::string reponseUtilisateur) const = 0;

protected:
	std::string d_intitule;
	std::string d_texte;

};
#endif //QUESTION_H
