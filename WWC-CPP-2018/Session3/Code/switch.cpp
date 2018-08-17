enum class Vessel { cup, glass, goblet, chalice };
void problematic(Vessel v)

{
     switch (v) {

     case Vessel::cup:       /* ... */    break;

     case Vessel::glass:     /* ... */    break;

     case Vessel::goblet:    /* ... */    break;

     }
}
