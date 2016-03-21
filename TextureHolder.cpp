#include "TextureHolder.hpp"


void TextureHolder::load(Textures::ID id ,const string& filename)
{
	unique_ptr<Texture> texture(new Texture());
	if(!texture->loadFromFile(filename)){
		throw std::runtime_error("TextureHolder::load - Failed to load "+filename);
	}


	mTextureMap.insert(make_pair(id,std::move(texture)));
}


Texture& TextureHolder::get(Textures::ID id)
{
	auto found = mTextureMap.find(id);
	return *found->second;
}
