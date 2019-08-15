using namespace std;
using namespace fastjet;
//----------------------------------------------------------------------------------------------------------------
// To associate extra information to a PseudoJet, one first has to create a class, derived from fastjet::UserInfoBase, that contains that information.
class MyInfo : public PseudoJet::UserInfoBase{
public:
  // default ctor
  MyInfo(const int & Index, const double & vertex_fX, const double & vertex_fY, const double & vertex_fZ) :
    _Index(Index), _vertex_fX(vertex_fX), _vertex_fY(vertex_fY), _vertex_fZ(vertex_fZ){}  //  - Index: the PDG id of the particle. - vertex_fX: theid of the vertex it originates from

  int Index() const { return _Index;}          // access to the PDG id
  double vertex_fX() const { return _vertex_fX;} // access to vertices
  double vertex_fY() const { return _vertex_fY;}
  double vertex_fZ() const { return _vertex_fZ;}

protected:
  int _Index;  double _vertex_fX;  double _vertex_fY;  double _vertex_fZ;  // the associated pdg id and vertex fCoordinates.
};
