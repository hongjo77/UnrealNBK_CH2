#include "Item.h"

Item::Item(const FString& InName) : Name(InName) {}

FString Item::GetName() const { return Name; }
