#ifndef INCLUDED_GAMELIB_FRAMEWORK_H
#define INCLUDED_GAMELIB_FRAMEWORK_H

namespace GameLib{

class Texture;

class Framework{
public:
	Framework();

	void update();

	static Framework instance();

	int width() const;

	int height() const;

	void requestEnd();

	bool isEndRequested() const;

	unsigned time() const;

	int frameRate() const;

	void setFrameRate( int );

	int previousFrameInterval() const;

	int getRandom( int max = 0 );

	void drawDebugString( 
		int column, 
		int row, 
		const char* string, 
		unsigned color = 0xffffffff );

	void drawTriangle3DH(
		const double* p0,
		const double* p1,
		const double* p2,
		const double* t0 = 0,
		const double* t1 = 0,
		const double* t2 = 0,
		unsigned c0 = 0xffffffff,
		unsigned c1 = 0xffffffff,
		unsigned c2 = 0xffffffff );

	void createTexture(
		Texture** textureOut,
		const char* filename );

	void destroyTexture( Texture** );

	void setTexture( const Texture* );

	void getTextureSizes( const Texture*, int* width, int* height, int* originalWidth, int* originalHeight );

	enum BlendMode{ 
		BLEND_LINEAR,
		BLEND_ADDITIVE,
		BLEND_OPAQUE,
	};
	void setBlendMode( BlendMode );
	void enableDepthTest( bool );
	void enableDepthWrite( bool );

	void start( void* windowHandle );
	void preUpdate();
	void postUpdate();
	static void create();
	static void destroy();
};

} //namespace GameLib

#include "GameLib/GameLib.h"

#endif
