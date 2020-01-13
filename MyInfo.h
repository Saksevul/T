using namespace std;
using namespace fastjet;
//------------------------------------------------------------------------------
// To associate extra information to a PseudoJet, one first has to create a
// class, derived from fastjet::UserInfoBase, that contains that information.
class MyInfo : public PseudoJet::UserInfoBase{
  public:

    MyInfo( const int & Index ) :
      _Index(Index){}                             // Index: Event[index].

    int Index() const { return _Index;}           // Access to the Event Index.

  protected:
    int _Index;                                   // The associated Event Index.
};
