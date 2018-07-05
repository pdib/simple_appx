$password = Read-Host -AsSecureString "Enter a password for the certificate"

$cert = New-SelfSignedCertificate -Type Custom -Subject "CN=TestCompany" -KeyUsage DigitalSignature -FriendlyName "Test company" -CertStoreLocation "Cert:\LocalMachine\My"

Export-PfxCertificate -cert $cert -FilePath MyKey.pfx -Password $password