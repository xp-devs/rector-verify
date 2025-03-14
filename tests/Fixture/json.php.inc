<?php

namespace Package\Tests\Fixture;

use PHPUnit\Framework\TestCase;

class SomeClassTest extends TestCase
{
    public function handlePasswordChange()
    {
        $this->assertJsonFileNotEqualsJsonFile($expected, $file);
        $this->assertJsonFileEqualsJsonFile($expected, $file);
        $this->assertJsonStringNotEqualsJsonFile($expected, $string);
        $this->assertJsonStringNotEqualsJsonString($expected, $string);
        $this->assertJsonStringEqualsJsonFile($expected, $string);
        $this->assertJsonStringEqualsJsonString($expected, $string);
    }
}

?>

-----
<?php

namespace Package\Tests\Fixture;

use PHPUnit\Framework\TestCase;

class SomeClassTest extends TestCase
{
    public function handlePasswordChange()
    {
        expect($file)->jsonFileNotToEqualJsonFile($expected);
        expect($file)->jsonFileToEqualJsonFile($expected);
        expect($string)->jsonStringNotToEqualJsonFile($expected);
        expect($string)->jsonStringNotToEqualJsonString($expected);
        expect($string)->jsonStringToEqualJsonFile($expected);
        expect($string)->jsonStringToEqualJsonString($expected);
    }
}

?>
