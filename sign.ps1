$password = Read-Host -AsSecureString "Private Key password: "
$BSTR = [System.Runtime.InteropServices.Marshal]::SecureStringToBSTR($password)
$UnsecurePassword = [System.Runtime.InteropServices.Marshal]::PtrToStringAuto($BSTR)

signtool sign /a /v /debug /fd SHA256 /f $PSScriptRoot\MyKey.pfx  $PSScriptRoot\appbundle.appx /p "${UnsecurePassword}"
