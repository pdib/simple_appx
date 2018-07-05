# Simple Appx

Decomposing an appx by creating it from scratch.

Ingredients
- AppxManifest.xml: declares some metadata and structure of the package. In particular, the entry point.
- application.exe: built from standard cpp files that use C++/WinRT. This just runs the startup of a UWP application.
- somes resources (images)

How to cook ?
- Compile the code.
- Put the manifest, the executable and the resources in a folder
- Package (running makeappx.exe, see build.cmd)
- Sign the package (you need a certificate, see create_certificate.ps1 and sign.ps1)
- Make sure the certificate you used above is somehow trusted (either signed by a Trusted Root or in Trusted People)
- Deploy your package.
