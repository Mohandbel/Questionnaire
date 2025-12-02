#include"Question.h"
#include<string>
Question::Question(std::string intitule, std::string texte):
	d_intitule{intitule},d_texte{texte}
{}
std::string Question::getIntitule()const
{
	return d_intitule;
}
std::string Question::getTexte()const
{
	return d_texte;
}
