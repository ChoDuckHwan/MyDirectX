#pragma once

#define ENTRYAPP(x) IApplication* EntryApplication() {return new (x);}

class MYDIRECTX_API IApplication
{
public:
	IApplication() {};

	~IApplication() {};

public:
	virtual void Initialize() = 0;

	virtual void Update() = 0;
};

IApplication* EntryApplication();