
module space_age
  implicit none
contains

  double precision function age_in_years(planet, seconds)
    character(len=*), intent(in) :: planet
    double precision, intent(in) :: seconds
    double precision :: earth_year_in_secs
    earth_year_in_secs = 31557600.0
    age_in_years = 0.d0
    select case (planet)
      case("Mercury")
        age_in_years = (seconds/0.2408467)/earth_year_in_secs
      case("Venus")
        age_in_years = seconds/(0.61519726 * earth_year_in_secs)
      case("Earth") 
        age_in_years = seconds/earth_year_in_secs
      case("Mars") 
        age_in_years = seconds/(1.8808158 * earth_year_in_secs)
      case("Jupiter") 
        age_in_years = seconds/(11.862615 * earth_year_in_secs)
      case("Saturn") 
        age_in_years = seconds/(29.447498 * earth_year_in_secs)
      case("Uranus") 
        age_in_years = seconds/(84.016846 * earth_year_in_secs)
      case("Neptune")   
        age_in_years = seconds/(164.79132 * earth_year_in_secs)
    end select

  end function

end module
