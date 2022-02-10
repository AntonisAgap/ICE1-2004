#include "matchedCourse.h"
MatchedCourse::MatchedCourse (mystring _oldId, mystring _oldName, mystring _newId, mystring _newName)
{
    oldId = _oldId;
    oldName = _oldName;
    newId = _newId;
    newName = _newName;
}

MatchedCourse::MatchedCourse (const MatchedCourse &MC)
{
	oldId = MC.oldId;
    oldName = MC.oldName;
    newId = MC.newId;
    newName = MC.newName;
}
