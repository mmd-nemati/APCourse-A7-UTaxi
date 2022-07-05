# UTaxi

This repository contains last project of UTAP 1400 course. 
<br> UTaxi is a [mobility as a service](https://en.wikipedia.org/wiki/Mobility_as_a_service) provider.


- This Web Application uses C++ for backend and HTML, CSS and plain JS for frontend.
- Powered by [APHTTP](https://github.com/UTAP/APHTTP)
___
To run the program:

1. clone this repo.
```
git clone https://github.com/mmd-nemati/UTaxi.git
```
2. Go to the repo directory:
```
cd UTaxi
```

3. Build application's objects:
```
make
```
4. Run it with given location file:
```
./utaxi.out locations.csv
```
5. Now UTaxi is running on port 5000. Go to your browser and enter ```http://localhost:5000```
> You can change the port in **/code/myserver.hpp** file.
___
- Server's log is written in terminal if you need it.
- Locations data file (locations.csv) can be modified. Add or delete locations **with given format**. 
- And of course you can change the website's UI. Front's files are in **/static** directory.
