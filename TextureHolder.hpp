#ifndef TEXTUREHOLDER_HPP
#define TEXTUREHOLDER_HPP

#include <SFML/Graphics.hpp>

#include <map>
#include <string>
#include <memory>
#include <stdexcept>

using namespace sf;

using namespace std;

namespace Textures
{
	enum ID {Block,Cross,Circle};
}


class TextureHolder
{
public:
	void load(Textures::ID,const string& filename);


	Texture& get(Textures::ID id);

	const Texture& get(Textures::ID id) const;

private:
	map<Textures::ID,unique_ptr<Texture> > mTextureMap;
};

#endif 
