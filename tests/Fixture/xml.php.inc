<?php

namespace Package\Tests\Fixture;

use PHPUnit\Framework\TestCase;

class SomeClassTest extends TestCase
{
    public function handlePasswordChange()
    {
        $this->assertXmlFileNotEqualsXmlFile($expected, $file);
        $this->assertXmlFileEqualsXmlFile($expected, $file);
        $this->assertXmlStringNotEqualsXmlFile($expected, $string);
        $this->assertXmlStringNotEqualsXmlString($expected, $string);
        $this->assertXmlStringEqualsXmlFile($expected, $string);
        $this->assertXmlStringEqualsXmlString($expected, $string);
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
        expect($file)->xmlFileNotToEqualXmlFile($expected);
        expect($file)->xmlFileToEqualXmlFile($expected);
        expect($string)->xmlStringNotToEqualXmlFile($expected);
        expect($string)->xmlStringNotToEqualXmlString($expected);
        expect($string)->xmlStringToEqualXmlFile($expected);
        expect($string)->xmlStringToEqualXmlString($expected);
    }
}

?>
